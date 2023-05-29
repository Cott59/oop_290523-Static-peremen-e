#include<iostream>
#include<vector>

class Client
{
private:
	std::string _name;
	int _id;
	static std::vector<Client *>_clients;
	void ShowClient()
	{
		std::cout << "Name: " << _name << '\n';
		std::cout << "id: " << _id << '\n';
		//for (const auto& it : _clients) // цикл фор выводит информацию о всех клиентах
		//	it->ShowClient();
	}
public:
	/*Client(std::string name, int id) : _name(name), _id(id)
	{
		_clients.push_back(this);
	}*/
	Client(std::string name, int id, std::vector<Client*>& client) : _name(name), _id(id)
	{
		client.push_back(this);
	}

	//static void ShowClient()
	//{
	//	/*std::cout << "Name: " << _name << '\n';
	//	std::cout << "id: " << _id << '\n';*/
	//	for (const auto& it : _clients) // цикл фор выводит информацию о всех клиентах
	//		it->ShowClient();
	//}
	void ShowClients(std::vector<Client*>& clients)
	{
		for (const auto& it : clients) // цикл фор выводит информацию о всех клиентах
			it->ShowClient();

	}


};

//std::vector<Client*>Client::_clients;// объ€вление вектора глобальное пространство класса Client




int main() {
	std::vector<Client*>client;
	Client* client1 = new Client("John", 20, client);
	Client* client2 = new Client("Alex", 16, client);
	Client* client3 = new Client("Bob", 32, client);
	/*client1->ShowClient();
	client2->ShowClient();
	client3->ShowClient();*/
	//Client::ShowClient();
	client1->ShowClients(client);
	return 0;
}