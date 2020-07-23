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


void inic(usuario&);
void pedirCancion(usuario&);
void pedirUsuario(usuario&);
void pedirUsuarios(usuario[]);
int indexUsuario(string,usuario[]);
usuario buscarUsuario(usuario[]);
void mostrarCancionesUsuario(usuario);

int main(){

    usuario usuarios[CANT_MAX_USUARIOS];
    int opc;

    do{

        do{
            cout<<"MENU:"<<endl;
            cout<<"\t(1) Ingresar Usuario + canciones"<<endl;
            cout<<"\t(2) Mostrar Usuario"<<endl;
            cout<<"\t(3) Salir"<<"\n"<<endl;
            cout<<"Que desea realizar?: ";
            cin>>opc;
            cin.ignore();
        }while(opc != 1 && opc != 2 && opc != 3);
        
        if(opc == 1){
            pedirUsuarios(usuarios);
        }
        else if(opc == 2){
            mostrarCancionesUsuario(buscarUsuario(usuarios));
        }


    }while(opc != 3);

    cout<<"Nos vemos!\n"<<endl;
    return 0;
}

void pedirCancion(usuario &usuario)
{
    
    int i = 0;
    int opc;

    do
    {
        cout<<"Okay "<<usuario.nombreUsuario<< " ingresa el Artista de tu cancion: ";
        getline(cin, usuario.canciones[i].nombreArtista);
        cout<<"Ingresa el Titulo de tu cancion: ";
        getline(cin,usuario.canciones[i].titulo);
        cout<<"Ingresa el Tamanio en KB de tu cancion: ";
        cin>>usuario.canciones[i].tamKB;
        cin.ignore();

        cout<<"\nQuerrias ingresar otra cancion? (Maximo de canciones: 3 por usuario)"<<endl;
        cout<< "1. SI" << endl;
        cout<< "2. NO" << "\n" << endl;
        cout<<"Opcion: ";
        cin>>opc;
        cout<<"\n";
        cin.ignore();
        i++;

    } while(i < CANT_MAX_CANCIONES && opc == 1);
    
}

void inic(usuario &usuario)
{

    for(int i=0;i<CANT_MAX_CANCIONES;i++){
        usuario.canciones[i].nombreArtista = "";
        usuario.canciones[i].titulo = "";
        usuario.canciones[i].tamKB = 0;
    }

}

void pedirUsuario(usuario &usuario)
{
    
    cout<<"\nCual es tu nombre?: ";
    getline(cin, usuario.nombreUsuario);
    cout<<"\n";
    inic(usuario);
    pedirCancion(usuario);

}

void pedirUsuarios(usuario usuarios[])
{
    int i = 0;
    int opc = 1;

    while(i < CANT_MAX_USUARIOS && opc == 1)
    {
        pedirUsuario(usuarios[i]);

        cout<<"\nQueres ingresar otro usuario?"<<endl;
        cout<<"1. SI"<<endl;
        cout<<"2. NO"<<endl;
        cout<<"\nOpcion: ";
        cin>>opc;
        cin.ignore();
        i++;

    }
}

usuario buscarUsuario(usuario usuarios[])
{

    string nombre;
    usuario mi_usuario;
    int index;

    cout<<"Tipee el usuario que desea buscar en los registros: ";
    getline(cin,nombre);

    for(int i=0;i<CANT_MAX_USUARIOS;i++){

        if(usuarios[i].nombreUsuario == nombre)
        {
            index = i;
        }
    }

    //Asignando los datos del usuario encontrado a la variable declarada a retornar
    mi_usuario.nombreUsuario = usuarios[index].nombreUsuario;
    for(int i=0;i<CANT_MAX_CANCIONES;i++){
        mi_usuario.canciones[i].nombreArtista = usuarios[index].canciones[i].nombreArtista;
        mi_usuario.canciones[i].titulo = usuarios[index].canciones[i].titulo;
        mi_usuario.canciones[i].tamKB = usuarios[index].canciones[i].tamKB;
    }

    return mi_usuario;
}

void mostrarCancionesUsuario(usuario usuario)
{
    int i = 0;
    cout<<"\nOkay "<<usuario.nombreUsuario<<"! Estas son tus canciones guardadas:\n"<<endl;
    while(i < CANT_MAX_CANCIONES && usuario.canciones[i].nombreArtista != "" ){
        cout<<"Nombre del Artista: "<<usuario.canciones[i].nombreArtista<<endl;
        cout<<"Titulo de la cancion: "<<usuario.canciones[i].titulo<<endl;
        cout<<"Tamaño de la cancion en KB: "<<usuario.canciones[i].tamKB<<"\n"<<endl;
        i++;
    }
}
