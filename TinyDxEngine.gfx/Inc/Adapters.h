#pragma once
#include "Logger.h"
#include "Singleton.h"
#include <vector>
#include <d3d11.h>
#include <wrl/client.h>

using namespace std;

class AdapterData
{
public:
    AdapterData(IDXGIAdapter* pAdapter);
    IDXGIAdapter* pAdapter = nullptr;
    DXGI_ADAPTER_DESC description;
};

class Adapters : public Singleton<Adapters>
{
public:
    Adapters();
    vector<AdapterData> GetAdapters();
private:
    vector<AdapterData> adapters;
};
