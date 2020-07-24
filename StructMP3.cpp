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
bool usrEncontrado(string);
int busqPosUsuario(string);
void usuarioNoExiste();
void mostrarUsuario();

bool esNumero(string); //Funcion para validar los inputs del usuario

int main(){

    inicReg(); //Inicializo el registro de usuarios
    string opc;
    int opci;
    do{
        mostrarMenu();
        getline(cin,opc);
        if(!esNumero(opc)){ //Valido que la entrada del usuario sea un int
            cout<<"Debe ingresar un valor numerico!"<<endl;
            continue;
        }
        //Una vez que ingreso el valor correcto procedo a transformar la entrada a dato de tipo int
        opci = stoi(opc);
        if(opci == 1){
            registrarUsuario();
            continue;
        }

        if(opci == 2){
            mostrarUsuario();
            continue;
        }

    }while( (opci != 1 || opci != 2) && (opci != 3) ); //Repito hasta que la opcion elegida sea 3
    
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
        string tam;
        cout<<"Okay "<<usuarios[pos].nombreUsuario<<"! Ingresa el nombre del Artista: ";
        getline(cin,usuarios[pos].canciones[i].nombreArtista);
        cout<<"Ingresa el titulo de la cancion: ";
        getline(cin,usuarios[pos].canciones[i].titulo);
        while(true){    
            cout<<"Ingresa el tamaño en KB de la cancion: ";
            getline(cin,tam);
            if(!esNumero(tam)){
                cout<<"El valor ingresado debe ser numerico!"<<endl;
                continue;
            }
            else{
                break;
            }
        }
        usuarios[pos].canciones[i].tamKB = stoi(tam);
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

void usuarioNoExiste(){
    cout<<"\nEl usuario que indico no existe en nuestros registros ;("<<endl;
    cout<<"Desea buscar otro usuario?\n"<<endl;
    cout<<"\t(1) SI"<<endl;
    cout<<"\t(2) NO"<<endl;
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

        usuarioNoExiste();
        string opc;
        int opci;

        do{
            cout<<"Opcion: ";
            getline(cin,opc);
            if(!esNumero(opc)){ //Valido que la entrada del usuario sea int
                cout<<"Debe ingresar un valor numerico!"<<endl;
                continue;
            }
            opci = stoi(opc);
        }while(opci != 1 && opci != 2);

        if(opci == 1){    
            mostrarUsuario();
        }
        else{
            cout<<"Okay!"<<endl;
        }
    }
}

bool esNumero(string cadena){
    bool esNum = true;
    for(int i=0;i<cadena.size();i++){
        if(cadena[i] < 48 || cadena[i] > 57){
            esNum = false;
        }
    }
    return esNum;
}