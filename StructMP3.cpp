#include <iostream>
#include <string> 

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
bool usrEncontrado();
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
            //mostrarUsuario();
            cout<<"This is working ;)"<<endl;
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
    }
}

void registrarUsuario(){
    string nombre;
    cout<<"Ingresa tu nombre de usuario: ";
    getline(cin,nombre);

    if(usrExiste(nombre)){
        registrarUsuario();
    }
    else{
            registrarCancionesUsuario(nombre);
    }
}
