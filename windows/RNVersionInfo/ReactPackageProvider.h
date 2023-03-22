#pragma once
#include "ReactPackageProvider.g.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::RNVersionInfo::implementation
{
    struct ReactPackageProvider : ReactPackageProviderT<ReactPackageProvider>
    {
        ReactPackageProvider() = default;

        void CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept;
    };
} // namespace winrt::RNVersionInfo::implementation

namespace winrt::RNVersionInfo::factory_implementation
{

struct ReactPackageProvider : ReactPackageProviderT<ReactPackageProvider, implementation::ReactPackageProvider> {};

} // namespace winrt::RNVersionInfo::factory_implementation
