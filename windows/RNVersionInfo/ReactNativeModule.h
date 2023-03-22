#pragma once

#include "JSValue.h"
#include "NativeModules.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::RNVersionInfo
{

REACT_MODULE(RNVersionInfoModule, L"RNVersionInfo")
struct RNVersionInfoModule
{
    REACT_INIT(Initialize)
    void Initialize(ReactContext const &reactContext) noexcept
    {
        m_reactContext = reactContext;
    }

	REACT_CONSTANT_PROVIDER(ConstantsProvider);
	void ConstantsProvider(ReactConstantProvider& provider) noexcept
	{
		auto appInfo = winrt::Windows::ApplicationModel::Package::Current().Id();
		winrt::Windows::ApplicationModel::PackageVersion version = appInfo.Version();
		char appVersion[256];
		StringCchPrintfA(appVersion, _countof(appVersion), "%d.%d.%d", version.Major, version.Minor, version.Build);

		provider.Add(L"appVersion", std::string(appVersion));
		provider.Add(L"buildVersion", std::to_string(version.Revision));
		provider.Add(L"bundleIdentifier", appInfo.Name());
	}

    private:
        ReactContext m_reactContext{nullptr};
};

} // namespace winrt::RNVersionInfo
