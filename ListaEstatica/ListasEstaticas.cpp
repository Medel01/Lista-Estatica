#include <iostream>
#include <string.h>
#define TAM 50

using namespace std;

class Mamifero
{
    private:
        int nacimiento;

        string lugar_nacimiento;
    public:
    Mamifero(int n, string ln): nacimiento(n), lugar_nacimiento(ln){}
    Mamifero():nacimiento(0), lugar_nacimiento(""){}
void imprimir_nacimiento(){
    cout<<"Ano de nacimiento: "<<nacimiento<<endl<<"\nLugar de nacimiento: "<<lugar_nacimiento;
            }
friend Mamifero operator + (Mamifero a, Mamifero b){
    return Mamifero(a.nacimiento + b.nacimiento, a.lugar_nacimiento + b.lugar_nacimiento);
        }
bool operator == ( Mamifero &a){
    if (nacimiento == a.nacimiento && lugar_nacimiento == a.lugar_nacimiento)
    {
        return true;
    }
    return false;
    }
bool operator != ( Mamifero &a){
    if (nacimiento != a.nacimiento || lugar_nacimiento != a.lugar_nacimiento)
    {
        return true;
    }
    return false;
}
bool operator < ( Mamifero &a){
    if (nacimiento < a.nacimiento)
    {
        return true;
    }
    return false;
}

bool operator > ( Mamifero &a){
    if (nacimiento > a.nacimiento)
    {
        return true;
    }
    return false;
}
int getnacimiento(){
    return nacimiento;
}
void setnacimiento(int nacimiento){
    this->nacimiento = nacimiento;
}
string getlugardenacimiento(){
    return lugar_nacimiento;
}
void setlugardenacimiento(string lugar_nacimiento){
    this->lugar_nacimiento = lugar_nacimiento;
}
};

class Felino : public Mamifero
{
    private:
    string dieta;
    string raza;
    string circo;

    public:
    Felino(int n, string ln, string d,string r, string c): Mamifero(n, ln), dieta(d), raza(r), circo(c){}
    Felino(): Mamifero(), dieta(""), raza(""), circo(""){}

    void imprimir_dieta(){
        cout<<"Su dieta es: "<<dieta<<endl;
    }

    void imprimir_raza(){
        cout<<"La raza es: "<<raza<<endl;
    }

    void cambiar_circo(string nuevo_circo){
        circo = nuevo_circo;
        cout<<"Nombre del circo cambiado!"<<endl;
    }
friend Felino operator + (Felino a, Felino b){
    a.setnacimiento(a.getnacimiento() + b.getnacimiento());
    a.setlugardenacimiento(a.getlugardenacimiento() + b.getlugardenacimiento());
    a.dieta += b.dieta;
    a.raza += b.raza;
    a.circo += b.circo;
    return Felino(a);
}
bool operator == (Felino &a){
    if (getnacimiento() == a.getnacimiento() && getlugardenacimiento() == a.getlugardenacimiento() && dieta == a.dieta && raza == a.raza && circo == a.circo)
    {
        return true;
    }
    return false;
}
bool operator != ( Felino &a){
    if (getnacimiento() != a.getnacimiento() || getlugardenacimiento() != a.getlugardenacimiento() || dieta != a.dieta || raza != a.raza || circo != a.circo)
    {
        return true;
    }
    return false;
}
bool operator < ( Felino &a){
    if (getnacimiento() < a.getnacimiento() && getlugardenacimiento() < a.getlugardenacimiento() && dieta < a.dieta && raza < a.raza && circo < a.circo)
    {
        return true;
    }
    return false;
}
    bool operator > ( Felino &a){
    if (getnacimiento() > a.getnacimiento() && getlugardenacimiento() > a.getlugardenacimiento() && dieta > a.dieta && raza > a.raza && circo > a.circo)
    {
        return true;
    }
    return false;
    }
        string getdieta(){
            return dieta;
        }
        void setdieta(string dieta){
            this->dieta = dieta;
        }
        string getraza(){
            return raza;
        }
        void setraza(string raza){
             this->raza = raza;
        }
        string getcirco(){
            return circo;
        }
        void setcirco(string circo){
             this->circo = circo;
        }
    };

class GatoDomestico : public Felino
{
private:
    string dueno;
public:
    GatoDomestico(int n, string ln, string d, string r, string c, string due): Felino(n, ln, d, r, c), dueno(due){}
    GatoDomestico(): Felino(), dueno(""){}

    void cambiar_dueno(string nuevo_dueno){
        dueno = nuevo_dueno;
        cout<<"Dueno cambiado!"<<endl;
    }
    string getdueno(){
        return dueno;
    }
    void setdueno (string dueno){
        this->dueno = dueno;
    }
    friend GatoDomestico operator + (GatoDomestico a, GatoDomestico b){
        a.setdieta(a.getdieta() + b.getdieta());
        a.setlugardenacimiento(a.getlugardenacimiento() + b.getlugardenacimiento());
        a.setdieta(a.getdieta() + b.getdieta());
        a.setraza(a.getraza() + b.getraza());
        a.setcirco(a.getcirco() + b.getcirco());
        a.dueno += b.dueno;
        return GatoDomestico(a);
    }

    bool operator == ( GatoDomestico &a){
        if (getnacimiento() == a.getnacimiento() && getlugardenacimiento() == a.getlugardenacimiento() && getdieta() == a.getdieta() && getraza() == a.getraza() && getcirco() == a.getcirco() && dueno == a.dueno)
        {
            return true;
        }
        return false;
    }

    bool operator != ( GatoDomestico &a){
        if (getnacimiento() != a.getnacimiento() || getlugardenacimiento() != a.getlugardenacimiento() || getdieta() != a.getdieta() || getraza() != a.getraza() || getcirco() != a.getcirco() || dueno == a.dueno)
        {
            return true;
        }
        return false;
    }

    bool operator < ( GatoDomestico &a){
        if (getnacimiento() < a.getnacimiento() && getlugardenacimiento() < a.getlugardenacimiento() && getdieta() < a.getdieta() && getraza() < a.getraza() && getcirco() < a.getcirco() && dueno < a.dueno)
        {
            return true;
        }
        return false;
    }
    bool operator > ( GatoDomestico &a){
        if (getnacimiento() > a.getnacimiento() && getlugardenacimiento() > a.getlugardenacimiento() && getdieta() > a.getdieta() && getraza() > a.getraza() && getcirco() > a.getcirco() && dueno > a.dueno)
        {
            return true;
        }
        return false;
    }

void mostrar(){
    cout<<"Anio de nacimiento:  ";
    cout<<getnacimiento()<<endl;
    cout<<"Lugar de nacimiento: ";
    cout<<getlugardenacimiento()<<endl;
    cout<<"Dieta: ";
    cout<<getdieta()<<endl;
    cout<<"Raza: ";
    cout<<getraza()<<endl;
    cout<<"Circo: ";
    cout<<getcirco()<<endl;
    cout<<"Dueno: ";
    cout<<dueno<<endl;
    }
friend ostream& operator <<(ostream& os, GatoDomestico gato){
    cout<<endl<<"Anio de nacimiento: ";
    os<<gato.getnacimiento()<<endl;
    cout<<"Lugar de nacimiento: ";
    os<<gato.getlugardenacimiento()<<endl;
    cout<<"Dieta: ";
    os<<gato.getdieta()<<endl;
    cout<<"Raza: ";
    os<<gato.getraza()<<endl;
    cout<<"Circo: ";
    os<<gato.getcirco()<<endl;
    cout<<"Dueno: ";
    os<<gato.dueno<<endl;
}
void obtener(){
    int aux;
    string aux2;
    cout<<endl<<"Ano de nacimiento: ";
    cin>>aux;
    setnacimiento(aux);
    cout<<"Lugar de nacimiento: ";
    fflush(stdin);
    getline(cin, aux2);
    setlugardenacimiento(aux2);
    cout<<"Dieta: ";
    fflush(stdin);
    getline(cin, aux2);
    setdieta(aux2);
    cout<<"Raza: ";
    fflush(stdin);
    getline(cin, aux2);
    setraza(aux2);
    cout<<"Circo: ";
    fflush(stdin);
    getline(cin, aux2);
    setcirco(aux2);
    cout<<"Nombre del dueno: ";
    fflush(stdin);
    getline(cin, aux2);
    setdueno(aux2);
}

friend istream& operator >>(istream& os, GatoDomestico gato){
    int aux;
    string aux2;
    cout<<endl<<"Ano de nacimiento: "<<endl;
    cin>>aux;
    gato.setnacimiento(aux);
    cout<<"Lugar de nacimiento: "<<endl;
    cin>>aux2;
    gato.setlugardenacimiento(aux2);
    cout<<"Dieta: "<<endl;
    cin>>aux2;
    gato.setdieta(aux2);
    cout<<"Raza: "<<endl;
    cin>>aux2;
    gato.setraza(aux2);
    cout<<"Circo: "<<endl;
    cin>>aux2;
    gato.setcirco(aux2);
    cout<<"Nombre del dueno: "<<endl;
    os>>gato.dueno;
}
};

class Lista{
private:
    GatoDomestico datos[TAM];
    int ult;

public:
    Lista(){
        ult = -1;
    }
    bool vacia()const{
        return ult==-1;
    }
    bool llena()const{
        return ult==TAM-1;
    }
    void agrega(GatoDomestico elem){
        if (!llena()){
            datos[ult + 1] = elem;
            ult++;
        }
        else{
            cout<<"No se pudo agregar"<<endl;
        }
    }
    bool inserta(GatoDomestico elem, int pos){
        if(llena() || pos < 0 || pos > ult + 1){
           cout<<"\n No se pudo insertar";
            return false;
        }
        for (int i = ult + 1; i > pos; i--){
            datos[i] = datos[i - 1];
        }
        datos[pos] = elem;
        ult++;
        return true;
    }
    int buscar(GatoDomestico elem){
        for (int i = 0; i <= ult; i++){
            if (elem == datos[i]){
                return i;
            }
            else{
                cout<<"Dato no encontrado";
            }
        }
        return -1;
    }
    bool elimina(int pos){
        if(vacia() || pos < 0 || pos > ult){
            cout<<"\n No se pudo eliminar";
            return false;
        }
        for (int i = pos; i < ult; i++){
            datos[i] = datos[i + 1];
        }
        ult--;
        return true;
    }
    void imprime(){
        if(!vacia()){
            for(int i = 0; i <= ult; i++){
                datos[i].mostrar();
            }
        }
}
    GatoDomestico recupera(int pos)const{
        if(vacia() || pos < 0 || pos > ult - 1){
            cout<<"\n Insuficiencia de datos";
        }
        else{
        return datos[pos];
        }
    }
    int primero()const{
        if(vacia()){
            return -1;
        }
        return 0;
    }
    int ultimo()const{
        if(vacia()){
            return -1;
        }
        return ult;
    }
};
int main(){
    Lista lis;
    GatoDomestico elem;
    int menu;
    int pos;
    string aux;

    do{
    system("cls");
    cout<<"Eliga una opcion."<<endl<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"1.Agrega"<<endl;
    cout<<"2.Buscar"<<endl;
    cout<<"3.Eliminar"<<endl;
    cout<<"4.Insertar"<<endl;
    cout<<"5.Mostrar"<<endl;
    cout<<"6.Salir"<<endl<<endl;
    cout<<"Opcion elegida: ";
    cin>>menu;

        switch (menu)
        {
case 1:
    system("cls");
    cout<<"Ingrese los datos del elemento gato domestico: ";
    elem.obtener();
    lis.agrega(elem);
    system("pause");

break;

case 2:
    system("cls");
    cout<<"Ingresa los datos del elemento gato domestico: ";
    cin>>elem;
      cout<<"Su dato esta en la posicion: "<<lis.buscar(elem);
      system("pause");

break;

case 3:
    system("cls");
    cout<<"Ingresa la posicion a eliminar: ";
    cin>>pos;
    lis.elimina(pos);
    system("pause");

break;

case 4:
    system("cls");
    cout<<"Ingresa los datos del elemento gato domestico: ";
    cin>>elem;
    cout<<"Ingresa la posicion: ";
    cin>>pos;
    lis.inserta(elem, pos);
    system("pause");

break;

case 5:
    system("cls");
    lis.imprime();
    system("pause");
break;
        }
    } while (menu != 6);


    return 0;
}
