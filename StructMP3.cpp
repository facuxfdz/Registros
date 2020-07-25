#include <iostream>
#include <string> 

using namespace std;

#define CANT_MAX_CANCIONES 3
#define CANT_MAX_USUARIOS 10

/*Defino dos estructuras:
    usuario: Guarda el nombre del usuario y las 3 canciones que haya ingresado
    cancionUsuario: Guarda los datos de cada cancion ingresada por el usuario
*/
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
            cout<<"\nDebe ingresar un valor numerico!"<<endl;
            continue;
        }

        opci = stoi(opc); //Paso el string a int
        if(opci == 1){
            registrarUsuario();
            continue;
        }

        if(opci == 2){
            mostrarUsuario();
            continue;
        }

    }while( (opci != 1 || opci != 2) && (opci != 3) ); //Repito hasta que la opcion elegida sea 3(SALIR)
    
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
    
    if(pos >= 0){//Si hay lugar para seguir metiendo usuarios procedo
        usuarios[pos].nombreUsuario = nombre;

        for(int i=0;i<CANT_MAX_CANCIONES;i++){
            string tam;
            cout<<"Okay "<<usuarios[pos].nombreUsuario<<"! Ingresa el nombre del Artista "<< i+1 <<": ";
            getline(cin,usuarios[pos].canciones[i].nombreArtista);
            cout<<"Ingresa el titulo de la cancion "<< i+1<<": ";
            getline(cin,usuarios[pos].canciones[i].titulo);
            while(true){    
                cout<<"Ingresa el tamaño en KB de la cancion "<< i+1 <<": ";
                getline(cin,tam);
                if(!esNumero(tam)){
                    cout<<"El valor ingresado debe ser numerico!\n"<<endl;
                    continue;
                }
                else{
                    break;
                }
            }
            usuarios[pos].canciones[i].tamKB = stoi(tam);
            cout<<"\n";
        }
        cout<<"Todo registrado correctamente!\n"<<endl;
    }
    else{
        cout<<"Ya se han ingresado todos los usuarios posibles :D"<<endl;
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


//Funciones para mostrar los datos del usuario

int busqPosUsuario(string nombre){
    for(int i=0;i<CANT_MAX_USUARIOS;i++){
        if(usuarios[i].nombreUsuario == nombre){
            return i;
        }
    }

    return -1; //Nunca va a ser retornado ya que si esta funcion tiene lugar es porque usrEncontrado() fue true
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
        cout<<"\nOkay "<<nombre<<"! Estas son tus canciones guardadas:\n"<<endl;
        for(int i=0;i<CANT_MAX_CANCIONES;i++){
            cout<<"\nNombre del artista: "<<usuarios[index].canciones[i].nombreArtista<<endl;
            cout<<"Nombre del titulo: "<<usuarios[index].canciones[i].titulo<<endl;
            cout<<"Tamanio en KB: "<<usuarios[index].canciones[i].tamKB<<endl;
        }
        cout<<"\n"<<endl;
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
            cout<<"Okay!\n"<<endl;
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