export module UNetDriver;
import UObject;
import UNetConnection;
import TArray;
import Offsets;

export class UNetDriver :public UObject {

public:
 UNetConnection m_ServerConnection{};
public:
	UObject::UObject;


	void update_ServerConnection();


};

void UNetDriver::update_ServerConnection()
{
	uint64_t addr = ptr + Offsets::UNetDriver::ServerConnection;
	dma::Read(addr , m_ServerConnection.get_ptr_data(), sizeof(uint64_t));

}