#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Stack {
  vector<string> items; //O(1)

  void push(const string& item) { //O(1)
    items.push_back(item);
  }

  string pop() { //O(1)
    if (!items.empty()) {
      string topItem = items.back();
      items.pop_back();
      return topItem;
    } 
    else {
      cerr << "Pila vacía, error." << endl;
      exit(1);
    }
  }

  bool isEmpty() { //O(1)
    return items.empty();
  }
//Como todas las funciones tienen una complejidad de O(1) podemos inferir que la estructura STACK/PILA tiene una complejidad O(1).
};

Stack titleStack; 
Stack artistStack; 
Stack yearStack;   

//PROTOTIPOS
void mostrarMainMenu();
void mostrarSong();
void ingresarCancion();
void mostrarOrdenTitle(Stack& titleStack);
void mostrarOrdenArtist(Stack& artistStack);
void mostrarOrdenAnio(Stack& yearStack);
void mostrarSinOrden();
int partition(Stack& arr, int low, int high);
void quickSort(Stack& arr, int low, int high);
void readFileAndPushToStack(const string& filename, Stack& stack);
void buscarCancion(Stack& titleStack);

//FUNCION MAIN
int main() {
  readFileAndPushToStack("title.txt", titleStack); //O(n log n)
  readFileAndPushToStack("artist.txt", artistStack);//O(n log n)              
  readFileAndPushToStack("year.txt", yearStack);//O(n log n)
  mostrarMainMenu();//O(1)

  return 0;
}

//FUNCIONES QUICKSORT

int partition(Stack& arr, int low, int high) {
  string pivot = arr.items[high]; //O(1)
  int i = low - 1; // O(1)

  for (int j = low; j < high; j++) { //Ciclo, O(n)
    if (arr.items[j] >= pivot) {
    i++;
    swap(arr.items[i], arr.items[j]); //O(1)
    }
  }

  swap(arr.items[i + 1], arr.items[high]); //O(1)
  return i + 1; //O(1)
}

void quickSort(Stack& arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high); //Llamado a partición, O(n)

    quickSort(arr, low, pi - 1); //Recursión, O(log n)
    quickSort(arr, pi + 1, high); //Recursión O(log n)
  }
}

//Complejidad total del algoritmo de ordenamiento quickSort, O(n log n)

//LECTURA DE ARCHIVO Y CARGA DE DATOS
void readFileAndPushToStack(const string& filename, Stack& stack) { 
  ifstream archivo(filename); //O(1)

  if (!archivo.is_open()) { //O(1)
    cerr << "Error: unable to open file " << filename << endl;
    exit(1);
  }

  string line; //O(1)
  set<string> existingItems(stack.items.begin(), stack.items.end()); //O(n)

  while (getline(archivo, line)) { //O(n)
    if (existingItems.find(line) == existingItems.end()) { //O(log n)
    // Line is not in the stack, so push it
    stack.push(line); //O(1)
    existingItems.insert(line); //O(log n)
    }
  }

  archivo.close(); //O(1)
}
//Notación final big O, O(n log n), ya que depende tanto del número de líneas del archivo como del tamaño de la pila.

//MOSTRAR CANCIONES
void mostrarSong() { //Ya podemos inferir que no es O(1) ya que está llamando a funciones que no son constantes. 
  int sel; //O(1)
  cout<<"\n[MENU DE MUESTRA DE CANCIONES]"<<endl; //O(1)
  cout << "\n1. Mostrar ordenadas por título" << endl; //O(1)
  cout << "2. Mostrar ordenadas por artistas" << endl; //O(1)
  cout << "3. Mostrar ordenadas por fecha" << endl; //O(1)
  cout << "4. Mostrar canciones ordenadas por orden de agregado" << endl; //O(1)
  cout<<"5. Regresar al menú principal"<<endl; //O(1)
  cin >> sel; //O(1)

  readFileAndPushToStack("title.txt", titleStack); //O(n log n)
  readFileAndPushToStack("artist.txt", artistStack); //O(n log n)
  readFileAndPushToStack("year.txt", yearStack); //O(n log n)

  switch (sel) {
    case 1:
      mostrarOrdenTitle(titleStack); //O(n log n)
      break;
    case 2:
      mostrarOrdenArtist(artistStack); //O(n log n)
      break;
    case 3:
      mostrarOrdenAnio(yearStack); //O(n log n)
      break;
    case 4:
      mostrarSinOrden(); //O(n)
      break;
    case 5:
      mostrarMainMenu(); //O(1)
    default:
      cerr<<"Opción no válida"<<endl;
      exit(1);
  }

}
//O(n log n) en el peor de los casos.

//ÚNICAMENTE MOSTRAR LISTA
void mostrarLista(Stack& titleStack){
  Stack miStack = titleStack; //O(1)

  cout << "\n[PLAYLIST]\n"<< endl; //O(1)

  int i = 1; //O(1)

  while (!miStack.isEmpty()) { //O(n)
    cout<<"["<<i<<"] "; //O(1)
    i++; //O(1)
    cout << miStack.pop() << " " << endl; //O(1)
  }

  cout << endl; //O(1)
 
}
//Complejidad total O(n) en el peor de los casos por el ciclo while.

//ORDENES

void mostrarOrdenTitle(Stack& titleStack) { //Las funciones mostrarOrdenArtist y mostrarOrdenYear tienen la misma complejidad porque tienen el mismo código.
  Stack miStack = titleStack; //O(1)

  quickSort(miStack, 0, miStack.items.size() - 1); //O(n log n)

  cout << "\n[PLAYLIST]\n"<< endl; //O(1)

  int i = 1; //O(1)

  while (!miStack.isEmpty()) { //O(n)
    cout<<"["<<i<<"] ";
    i++;
    cout << miStack.pop() << " " << endl;
  }

  cout << endl; //O(1)
  mostrarSong(); //O(1)
}

void mostrarOrdenArtist(Stack& artistStack) {
  Stack miStack = artistStack;

  quickSort(miStack, 0, miStack.items.size() - 1);

  cout << "\n[PLAYLIST]\n"<< endl;

  int i = 1;

  while (!miStack.isEmpty()) {
    cout<<"["<<i<<"] ";
    i++;
    cout << miStack.pop() << " " << endl;
  }

  cout << endl;
  mostrarSong();
}

void mostrarOrdenAnio(Stack& yearStack) {
  Stack miStack = yearStack;

  quickSort(miStack, 0, miStack.items.size() - 1);
  cout << "\n[PLAYLIST]\n"<< endl;

  int i = 1;

  while (!miStack.isEmpty()) {
    cout<<"["<<i<<"] ";
    i++;
    cout << miStack.pop() << " " << endl;
  }
  cout << endl;
  mostrarSong();
}

void mostrarSinOrden(){
  Stack miStack = titleStack;

  cout<<"\n[PLAYLIST]\n"<<endl;

  int i = 1;

  while(!miStack.isEmpty()){
    cout<<"["<<i<<"] ";
    i++;
    cout<<miStack.pop()<<" "<<endl;
  }
  cout<<endl;
  mostrarSong();
}
//Como no tiene la función de quickSort, la función sólamente tiene un O(n) de complejidad.

//MENÚ
void mostrarMainMenu() {
  int chc; //O(1)
  cout << "\n[MENU]\n" << endl; //O(1)
  cout << "1. Mostrar Playlist" << endl; //O(1)
  cout << "2. Agregar canción" << endl; //O(1)
  cout << "3. Buscar canción por título" << endl; //O(1)
  cout << "4. Salir"<<endl; //O(1)
  cin >> chc; //O(1)

  switch (chc) {
    case 1:
      mostrarSong();  //O(n log n)
      break;
    case 2:
      ingresarCancion(); //O(1)
      break;
    case 3:
      buscarCancion(titleStack); //O(n^2)
      break;
    case 4:
      exit(1);
    default:
      cerr << "Opción no válida" << endl;
      exit(1);
  }
}
//O(n^2) en el peor de los casos

//MODIFICAR PLAYLIST
void ingresarCancion() {
  ofstream titleFile; //O(1)
  ofstream artistFile; //O(1)
  ofstream yearFile; //O(1)

  titleFile.open("title.txt", ios::app); //O(1)
  artistFile.open("artist.txt", ios::app); //O(1)
  yearFile.open("year.txt", ios::app); //O(1)

  if (titleFile.fail() || artistFile.fail() || yearFile.fail()) { //O(1)
    cerr << "Error.";
    exit(1);
  }

  string title; //O(1)
  string artist; //O(1)
  int year; //O(1)

  cout << "Título: "; //O(1)
  cin.ignore(); //O(1)
  getline(cin, title); //O(1)
  titleFile << title << ", "; //O(1)

  cout << "Artista: "; //Complejidad igual a Título
  getline(cin, artist);
  artistFile << artist << ", ";

  cout << "Año de lanzamiento: "; //Complejidad igual a título
  cin >> year;
  yearFile << year << ", ";

  //Title; la complejidad es O(1) en todas las líneas siguientes dentro de la funcón
  titleFile << artist << ", ";
  titleFile << year << endl;
  // Artists
  artistFile << title << ", ";
  artistFile << year << endl;

  // Years
  yearFile << title << ", ";
  yearFile << artist << endl;

  titleFile.close();
  artistFile.close();
  yearFile.close();

  mostrarMainMenu(); 
}
//La complejidad es O(1) debido a que todas las funciones llamadas son O(1)

//BÚSQUEDA

void buscarCancion(Stack& titleStack) {
  cin.ignore(); //O(1)

  cout << "\n[Buscar canción por título]\n"; //O(1)
  cout << "Ingrese el título de la canción: "; //O(1)

  string searchTitle; //O(1)
  getline(cin, searchTitle); //O(n)

  transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower); //O(n)

  Stack tempStack = titleStack;
  bool found = false;
  int index = 1;

  while (!tempStack.isEmpty()) { //O(n^2)
    string currentTitleOriginal = tempStack.pop();
    string currentTitle = currentTitleOriginal;


    transform(currentTitle.begin(), currentTitle.end(), currentTitle.begin(), ::tolower); //O(n)

    if (currentTitle.find(searchTitle) != string::npos) {
      cout << currentTitleOriginal << endl;
      found = true;
    } //O(n)

    index++;
  }

  if (!found) {
    cout << "No se encontraron canciones con ese título." << endl;
  }


  mostrarMainMenu();
}

//Complejidad O(n^2) en el peor de los casos

//La complejidad total del programa es O(n^2), influenciado por la función buscarCancion en la que se hace una búsqueda dentro de un bucle.