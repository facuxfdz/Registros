#include <iostream>
#include <string> 
#include <sstream>

using namespace std;

#define CANT_MAX_CANCIONES 3
#define CANT_MAX_USUARIOS 10

struct 
{
    string nombreArtista;
    string titulo;
    int tamKB;

}typedef cancionUsuario;

struct
{
    string nombreUsuario;
    cancionUsuario canciones[CANT_MAX_CANCIONES];
}typedef usuario;

/*Defino la variable de manera global porque así va a ser mas facil
acceder con las distintas funciones */
usuario usuarios[CANT_MAX_USUARIOS];

void mostrarMenu();
void inicReg();

//Funciones para el registro
void registrarCancionesUsuario(string);
bool usrExiste(string);
int busqPos();
void registrarUsuario();

//Funciones para la busqueda y muestra
bool usrEncontrado(string);
int busqPosUsuario(string);
void mostrarUsuario();

int main(){

    inicReg(); //Inicializo el registro de usuarios
    int opc;
    do{
        mostrarMenu();
        cin>>opc;
        cin.ignore();
        if(opc == 1){
            registrarUsuario();
            continue;
        }

        if(opc == 2){
            mostrarUsuario();
            continue;
        }

    }while( (opc != 1 || opc != 2) && (opc != 3) );
    
    cout<<"Nos vemos!\n"<<endl;
    return 0;
}

void inicReg(){
    for(int i=0;i<CANT_MAX_USUARIOS;i++){
        usuarios[i].nombreUsuario = "";
    }
}

void mostrarMenu(){

    cout<<"MENU:"<<endl;
    cout<<"\t(1) Ingresar Usuario + canciones"<<endl;
    cout<<"\t(2) Mostrar Usuario"<<endl;
    cout<<"\t(3) Salir"<<"\n"<<endl;
    cout<<"Que desea realizar?: ";

}

//Funciones para el registro

bool usrExiste(string nombre){
    bool encontrado = false;
    for(int i=0;i<CANT_MAX_USUARIOS;i++){
        if(usuarios[i].nombreUsuario == nombre){
            encontrado = true;
        }
    }
    return encontrado;
}

int busqPos(){
    for(int i=0;i<CANT_MAX_USUARIOS;i++){
        if(usuarios[i].nombreUsuario == ""){
            return i;
        }
    }
    return -1;
}

void registrarCancionesUsuario(string nombre){
    int pos = busqPos(); //Defino el lugar a partir del cual registrar el usuario

    usuarios[pos].nombreUsuario = nombre;
    for(int i=0;i<CANT_MAX_CANCIONES;i++){
        cout<<"Okay "<<usuarios[pos].nombreUsuario<<"! Ingresa el nombre del Artista: ";
        getline(cin,usuarios[pos].canciones[i].nombreArtista);
        cout<<"Ingresa el titulo de la cancion: ";
        getline(cin,usuarios[pos].canciones[i].titulo);
        cout<<"Ingresa el tamaño en KB de la cancion: ";
        cin >> usuarios[pos].canciones[i].tamKB;
        cin.ignore();
        cout<<"\n";
    }
}

void registrarUsuario(){
    string nombre;
    cout<<"Ingresa tu nombre de usuario: ";
    getline(cin,nombre);
    cout<<"\n";

    if(usrExiste(nombre)){
        cout<<"Ya existe un usuario con ese nombre registrado ;(\n"<<endl;
        registrarUsuario();
    }
    else{
            registrarCancionesUsuario(nombre);
    }
}

int busqPosUsuario(string nombre){
    for(int i=0;i<CANT_MAX_USUARIOS;i++){
        if(usuarios[i].nombreUsuario == nombre){
            return i;
        }
    }
    return -1;
}

bool usrEncontrado(string nombre){
    bool encontrado = false;
    for(int i=0;i<CANT_MAX_USUARIOS;i++){
        if(usuarios[i].nombreUsuario == nombre){
            encontrado = true;
        }
    }
    return encontrado;
}

void mostrarUsuario(){
    string nombre;
    int index;
    cout<<"\nQue usuario desea buscar?: ";
    getline(cin,nombre);

    if(usrEncontrado(nombre)){
        index = busqPosUsuario(nombre);
        for(int i=0;i<CANT_MAX_CANCIONES;i++){
            cout<<"\nNombre del artista: "<<usuarios[index].canciones[i].nombreArtista<<endl;
            cout<<"Nombre del titulo: "<<usuarios[index].canciones[i].titulo<<endl;
            cout<<"Tamanio en KB: "<<usuarios[index].canciones[i].tamKB<<endl;
        }
    }
    else{
        int opc;
        cout<<"\nEl usuario que indico no existe en nuestros registros ;("<<endl;
        cout<<"Desea buscar otro usuario?\n"<<endl;
        cout<<"\t(1) SI"<<endl;
        cout<<"\t(2) NO"<<endl;
        do{
            cout<<"Opcion: ";
            cin>>opc;
            cin.ignore();
        }while(opc != 1 && opc != 2);

        if(opc == 1){    
            mostrarUsuario();
        }
        else{
            cout<<"Okay!"<<endl;
        }
    }
}
