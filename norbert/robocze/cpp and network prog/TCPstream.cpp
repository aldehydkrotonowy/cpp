// based on:
// https://vichargrave.github.io/articles/2013-02/tcp-ip-network-programming-design-patterns-in-cpp

// ten plik na razie zostanie niedokończony bo dalej nie rozumiem tego poradnika

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>

using namespace std;

class TCPstream{
    int m_sd;
    string m_peerIP;
    int m_peerPort;

public:
    friend class TCPAcceptor;
    friend class TSPConnector;

    ~TCPStream();

    ssize_t send(char* buff, size_t len);
    ssize_t receive(char* buff, size_t len);

    string getPeerIP();
    int getPeerPort();

private:
    TCPStream(int sd,struct socketaddr_in* addres)
    TCPStream();
    TCPStream(const TSPStream& stream);
}