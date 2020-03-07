DDE stara technologia, która pozwalała na wymianę małych porcji danych między uruchomionymi aplikacjami.
OLE server and client communicate with system libraries using VTBL.
VTBL consists of structure of function pointers that the system library use to communicate with server or client.
OLESVR.DLL – provides services for OLE server applications. Bidirectional communication take place betweene server application and OLE server library.

https://support.microsoft.com/en-us/help/86008/ole-concepts-and-requirements-overview

OLECLI.DLL – The OLE client library
OLECLI.DLL, the OLE client library in the Microsoft Windows environment, provides services to simplify an OLE client application. Bidirectional communication takes place between a client application and the OLE client library. A client application calls functions in the client library to perform OLE tasks such as object creation, rendering, loading, and saving. The client library sends status information to the application by calling an application-defined callback function. The status data the library passes to the client's callback function includes notification that an object has been changed, renamed, saved, or closed by an OLE server application.

OLESER.DLL – The OLE server library
OLESVR.DLL, the OLE server library, provides services for an OLE server application. Bidirectional communication takes place between a server application and the OLE server library. A server application calls functions in the server library to register itself as available, or to revoke its availability. It also calls server library functions to indicate when it saves or renames a document. The server library conveys information to the server application through a set of 27 application-defined callback functions. Each of the server application's callback functions, which are commonly called methods, is called to request that the server perform a specific action, or to inform it that a specific event has occurred.

Object Handler
An end-user is typically concerned only with two types of OLE applications: client applications and server applications. However, an application developer must also be aware of a third type of OLE module called an object handler. An object handler is a dynamic-link library (DLL) that can be conceptualized as a limited-function server application. An object handler contains functions required to support a server application's object classes. For example, when a client application invokes an object's verb, this call can be processed by an object handler that loads into memory, processes the call, and unloads from memory without any assistance from the main server application. An object handler provides an efficient way to manage objects, because a handler is typically small and can be loaded and unloaded more efficiently than an (often large) full-function server application. An object handler is implemented using the OLE server library just like a fully-functioned server application.

VTBL
As noted above, communication from the OLE client library to a client application, and from the OLE server library to a server application, takes place through application-defined callback functions. During the initialization of a client or server application, it calls the appropriate library with a pointer to a VTBL data structure. The library uses the pointers in the VTBL to call the application's callback functions.

For example, one of the VTBLs that a server application provides to the OLE server library is called an OLESERVERVTBL. The server application fills the OLESERVERVTBL structure with pointers to six callback functions that implement the Create, CreateFromTemplate, Edit, Exit, Open, and Release methods. Once the server application passes the initialized VTBL to the server library, the library can call any of the six methods just by dereferencing pointers in the VTBL. Note that using a VTBL allows the OLE libraries to call an application-defined function that implements a method independent of the function's name.

To programmers familiar with the C++ language, the VTBL concept may seem similar to the C++ virtual method concept. In fact, VTBLs and virtual methods are closely related. A VTBL allows the OLE libraries to specify the methods that a client or server application must implement, while allowing the implementation of each method to be defined differently for each object class.




DDE	– dynamic data exchange
SLF	– server library function
OLE	– object linking and embeding



OLEDB was designed as higher-level replacement for ODBC to support wider variety of non-relational databases that do not necesairly implement SQL. OLE has a client-provider model, where clients requests access to data and providers are the software components interfaces that allow access to data.


ODBC – open database conectivity (more commonly used therm than SQL CLI)
MDAC – microsoft data acces components
DSO – data source object
SISS – SQL Server Integration Service
//------------------------------------------------------------------------------------------
Coclass is said to implement those interfaces. COM object is an instance of coclass in memory. COM class is not the same as C++ class although it is often the case than implementation of coclass is the same as C++ class.

GUID - globally unique identifier, 128-bit number. It's COM's language independent way to identifiing things.

IDD - interface ID
CLSID - class ID

The interface makes clear boundary between the code that calls method and code that implements method. In computer science terms,
the caller is decoupled from the implementation.



//manipulation of Shape and Triangle through IDrawable pointers
IDrawable *pDrawable = CreateTriangleShape();

void drawSomeShape (IDrawable **drawableArray, size_t count){
  for (size_t i = 0; i < count; i++){
    drawableArray[i]->do {
      /* code */
    } while(/* condition */);raw();
  }
}

HRESULT CoCreateInstance (
  REFCLSID  rclsid,       //clsid of the class
  LPUNKNOWN pUnkOther,    //com object composition
  DWORD     dwClsContext, //what kind of COM server we want to use
  REFID     riid          //IID of the interface
  LPVOID    ppv           //adres of the interface pointer
)
