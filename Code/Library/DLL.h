#pragma once

#include "WinAPI.h"

class DLL
{
public:
	// flags
	enum
	{
		NO_UNLOAD = (1 << 0),  // do not unload the library
		REF_ONLY  = (1 << 1),  // do not load and unload the library, only obtain its handle
	};

private:
	void *m_handle;
	int m_flags;

	// no copies
	DLL(const DLL &);
	DLL & operator=(const DLL &);

public:
	DLL()
	: m_handle(NULL),
	  m_flags(0)
	{
	}

	explicit DLL(const char *name, int flags = 0)
	: m_handle(NULL),
	  m_flags(0)
	{
		Load(name, flags);
	}

	~DLL()
	{
		Unload();
	}

	bool TryLoad(const char *name, int flags = 0)
	{
		Unload();

		void *handle = (flags & REF_ONLY) ? WinAPI::DLL_Get(name) : WinAPI::DLL_Load(name);
		if (!handle)
		{
			return false;
		}

		m_handle = handle;
		m_flags = flags;

		return true;
	}

	void Load(const char *name, int flags = 0)
	{
		if (!TryLoad(name, flags))
		{
			throw WinAPI::MakeError("Failed to load %s", name);
		}
	}

	void Unload()
	{
		if (IsLoaded() && IsUnloadAllowed())
		{
			WinAPI::DLL_Unload(m_handle);
		}

		m_handle = NULL;
		m_flags = 0;
	}

	bool IsLoaded() const
	{
		return m_handle != NULL;
	}

	bool IsUnloadAllowed() const
	{
		return !(m_flags & NO_UNLOAD) && !(m_flags & REF_ONLY);
	}

	void *GetHandle() const
	{
		return m_handle;
	}

	int GetFlags() const
	{
		return m_flags;
	}

	void *GetSymbolAddress(const char *name) const
	{
		return IsLoaded() ? WinAPI::DLL_GetSymbol(m_handle, name) : NULL;
	}

	template<class T>
	T GetSymbol(const char *name) const
	{
		return reinterpret_cast<T>(GetSymbolAddress(name));
	}
};
