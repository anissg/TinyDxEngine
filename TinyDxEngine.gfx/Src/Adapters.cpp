#include "Adapters.h"

using namespace Microsoft::WRL;

Adapters::Adapters()
{
    ComPtr<IDXGIFactory> pFactory;
    HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), reinterpret_cast<void**>(pFactory.GetAddressOf()));
    if (FAILED(hr))
    {
        Logger::get().Log("Failed to create DXGIFactory for enumerating adapters.", ERR);
        exit(-1);
    }

    IDXGIAdapter* pAdapter;
    UINT index = 0;
    while (SUCCEEDED(pFactory->EnumAdapters(index, &pAdapter)))
    {
        adapters.push_back(AdapterData(pAdapter));
        index += 1;
    }
}

vector<AdapterData> Adapters::GetAdapters()
{
    return adapters;
}

AdapterData::AdapterData(IDXGIAdapter * pAdapter)
{
    this->pAdapter = pAdapter;
    HRESULT hr = pAdapter->GetDesc(&this->description);
    if (FAILED(hr))
    {
        Logger::get().Log("Failed to Get Description for IDXGIAdapter.", ERR);
    }
}