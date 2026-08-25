export module UVehicleCommonComponent;
import UObject;
import Offsets;
import dma;
import TArray;
import std;

export class UVehicleCommonComponent : public UObject
{
public:
	using UObject::UObject;

	float m_HPMax{};
	float m_HP{};
	float m_FuelMax{};
	float m_Fuel{};
	TArray<float> m_WheelsCurrentHP_TArray{};
	std::vector<float> m_WheelsCurrentHP{};

	void scatter_HPMax(VMMDLL_SCATTER_HANDLE hs);
	void scatter_HP(VMMDLL_SCATTER_HANDLE hs);
	void scatter_FuelMax(VMMDLL_SCATTER_HANDLE hs);
	void scatter_Fuel(VMMDLL_SCATTER_HANDLE hs);
	void scatter_WheelsCurrentHP_TArray(VMMDLL_SCATTER_HANDLE hs);
	void scatter_WheelsCurrentHP_Data(VMMDLL_SCATTER_HANDLE hs);
};

void UVehicleCommonComponent::scatter_HPMax(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::UVehicleCommonComponent::HPMax, &m_HPMax, sizeof(float));
}

void UVehicleCommonComponent::scatter_HP(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::UVehicleCommonComponent::HP, &m_HP, sizeof(float));
}

void UVehicleCommonComponent::scatter_FuelMax(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::UVehicleCommonComponent::FuelMax, &m_FuelMax, sizeof(float));
}

void UVehicleCommonComponent::scatter_Fuel(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::UVehicleCommonComponent::Fuel, &m_Fuel, sizeof(float));
}

void UVehicleCommonComponent::scatter_WheelsCurrentHP_TArray(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::UVehicleCommonComponent::WheelsCurrentHP, &m_WheelsCurrentHP_TArray, sizeof(TArray<float>));
}

void UVehicleCommonComponent::scatter_WheelsCurrentHP_Data(VMMDLL_SCATTER_HANDLE hs)
{
	if (m_WheelsCurrentHP_TArray.NumElements > 0 && m_WheelsCurrentHP_TArray.NumElements < 20) {
		m_WheelsCurrentHP.resize(m_WheelsCurrentHP_TArray.NumElements);
		dma::Scatter_PrepareEx(hs, m_WheelsCurrentHP_TArray.Data, m_WheelsCurrentHP.data(), m_WheelsCurrentHP_TArray.NumElements * sizeof(float));
	}
}
