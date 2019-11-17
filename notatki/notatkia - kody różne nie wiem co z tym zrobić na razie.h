#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> tab;
	tab.push_back(0);
	for (int i=0; i<100; i++){
		int gdzie = rand() % tab.size();
		tab.insert(tab.begin() + gdzie, i);
	}
	
int main(){
	vector<int> lolek;
	tab.push_back(0);
	for (int i=0; i<100; i++){
		int gdzie = rand() % tab.size();
		tab.insert(tab.begin()+gdzie, i);
	}
	for (i=0; i<tab.size(); i++){
		cout<<"wartość na miejscu "<<i<<" wynosi "<<tab[i];
	}
	return 0;
}

{/*inne przydatne funkcje w klasie <vector>
std::vector<typ> nazwa;
tab.begin();
tab.end();
tab.insert();
tab.size();
tab.push_back();
tab.pop_back(); 	- usówanie z konca
tab.erase(n); 		- usówa n-ty element, resztę przesówa na jego miejsce. Uwaga na begin()+3=4 bo begin() zwraaca 1 a nie 0 jak jest liczone w tablicach
tab.erase(x,y);	- usuniecie wszystkiego pomiędzy x i y
tab.resize(n); 	- zmiana wektora do wielkości n
tab.clear();		- usunięcie wszystkiego


sortowania kontenerów dokonujem przy pomocy <alghorithm>*/}
int main(){
	vector<long> kura;
	for(int i=0; i<100; i++){
		int pozycja = rand() % kura.size();
		kura.insert(kura.begin() + gdzie, i);
	}
	sort(kura.begin(), kura.end());//sortowanie kontenera dzięki algorithm
	for (int j=0; j<kura.length(); j++){
		cout<<"posortowana zawartość wygląda tak: "<<endl;
		cout<<kura[i];
	}
	return 0;
}

//tutaj do wektora wsadzam klasę
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>
class czlowiek {
	public:
		string imie;
		string nazwisko;
		int wzrost;
		int numer;
		czlowiek (string ximie, string xnazwisko, int wzrost, int xnumer);
};
	
int main(){
	vector<czlowiek> damulka;
	cout<"Baza osob\n 1-lista osob \n 2-dodaj osobe\n 3-wyjscie";
	char odp;
	do {
		odp = getch();
		swith(odp){
		case '1':
			cout<<"\n\n\nLista osob";
			for (int i =0; i<damulka.size(); i++){
				cout<<endl;
				cout<<"imie: "<<damulka[i].imie<<endl;
				cout<<"nazwisko: "<<damulka[i].nazwisko<<endl;
				cout<<"wzrost: "<<damulka[i].wzrost<endl;
				cout<<"numer: "<<damulka[i].numer<<endl;
			}break;
		case '2':
			cout<<n\n\n\ Dodawanie osob<<endl;
			cout<<"podaj imie osoby"<<endl;
			string odpImie;
			cin>>odpImie;
			cout<<"podaj nazwisko osoby"<<endl;
			string odpNazwisko;
			cin>>odpNazwisko;
			cout<<"podaj wzrost osoby"<<endl;
			int odpWzrost;
			cin>>odpWzrost;
			cout<<"podaj numer osoby"<<endl;
			int odpNumer;
			cin>>odpNumer;
			damulka.push_back(czlowiek(odpImie, odpNazwisko, odpWzrost, odpNumer));
			cout<<"---Dodano osobe---"<<endl;
			break;}}
	while(odp!='3');
	return 0;
}
czlowiek::czlowiek(string ximie, string xnazwisko, int xwzrost, int xnumer):
	imie(ximie),
	nazwisko(xnazwisko),
	wzrost(xwzrost),
	numer(xnumer)
	{}} 
//
//
//
//używanie wektora z iteratorem
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector < int > tab;
    for( int i = 0; i < 10; i++ )
         tab.push_back( i );
    
    vector < int >::iterator it_tab = tab.begin();
    for(; it_tab != tab.end(); it_tab++ )
         cout <<* it_tab;
    
}
/////////////////////////////////////////////////////////////////////
kontenery dzielimy na: sequence containers, associative containers and container adapters.
3 Secuence containers:
	vectors
	deque 	- vectors that can grow from both ends
	list 	- doubly linked list. Each element in the list contains pointers that points at the next and prewious element. List provide acces to the start
				and end of the list. You must "walk" the list until you reach element that you want.
4 Associative containers:
	map					- key/walue
	multimap (dictionary)	- 
	set					- unique elements only
	multiset				- duplicated elements are allawed
3 Container adapters
	stack	- LIFO
	queue	- FIFO
	priority queue
/////////////////////////////////////////////////////////////////////
#include <windows.h>
const char g_szClassName[] = "MyWindowClass";
//Windows Procedure
LRESULT CALLBACK WndProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
        {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc (hwnd, msg, wParam, lParam);
        }
        return 0;
}
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Registering
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Faild!", "Error!", MB_ICONEXCLAMATION|MB_OK);
        return 0;
    }
    //Create Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "The title of my window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
        NULL, NULL, hInstance, NULL);
    if(hwnd==NULL)
    {
        MessageBox(NULL, "Window Creation Faild", "ERROR!", MB_ICONEXCLAMATION|MB_OK);
        return 0;
    }
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    //Loop message
    //GetMessage() gets a message from your application's message queue.
    while(GetMessage(&Msg, NULL, 0, 0)>0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    /*When either GetMessage and PeekMessage see a WM_QUIT message,
     they will return zero, and you can check for the exit code in
     the WPARAM part of the LPMSG parameter.*/
    return Msg.wParam;
}
///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////
SendMessage() is synchronous. This function sends specific message to the window or windows. The SendMessage function calls  windows procedure for the specific window, and does not return until the windows procedure has proccede the message.




