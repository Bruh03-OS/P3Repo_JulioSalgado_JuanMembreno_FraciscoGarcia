#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int getMeSize(int digito) {
    int contador = 1, i = 2;
    while(digito != 1) {
        if(digito % i == 0) {
            contador++;
            digito /= i;
        }
        else
            i++;
    }
    return contador;
}
int *burbujaChingona(int *arr, int size) {
    int temp = 0;
    for (int i = 1; i < size; i++){
        for(int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}
int *simplificacion(int digito, int size) {
    int *arr = new int[size];
    int i = 2, contador = 0;
    cout << "Simplificacion: \n";
    while(digito != 1) {
        if(digito % i == 0) {
            arr[contador] = digito;
            digito /= i;
            cout << digito << endl;
            contador++;
        }
        else
            i++;
    }
    arr[contador] = 1;
    arr = burbujaChingona(arr, size);
    return arr;
}
void impresion(int *arr, int size) {
    cout << "Arreglo Generado: ";
    for (int i = 0; i < size; i++) {
        cout << "[" << arr[i] << "]";
    }
}
double raizCuadrada(int* arr, int size, double x, double epsilon, double min, double max) {
    double rmed = (min + max) / 2;
    double gamma = pow(10, -epsilon);
    bool siu = false;
    do{
        if(((x - gamma) <= (rmed * rmed)) && ((rmed * rmed) <= (x + gamma)))
            siu = true;
		if ((x - gamma) <= (rmed * rmed)) {
			max = rmed;
            rmed = (double)((min + max) / 2);
		}
		else if ((rmed * rmed) <= (x + gamma)) {
			min = rmed;
            rmed = (double)((min + max) / 2);
		}
	} while (!siu);
	return rmed;
}
void guardarArchivo(int numero, double res) {
    ofstream archivo("raizCuadrada.txt", ios::app);
    archivo << "La raiz Generada de " << numero << " es: " << res << ";\n";
    archivo.close();
}
int main() {
    int digito, resultado, i = 2, size = 0, epsilon;
    int *arr;
    cout << "\nIngrese un numero de 6 digitos: ";
    cin >> digito;
    while(digito < 99999 || digito > 999999) {
        cout << "Nel bro, solo son 6 digitos: ";
        cin >> digito;
    }
    cout << "Ingrese Epsilon: ";
    cin >> epsilon;
    while(epsilon < 1 || epsilon > 5) {
        cout << "Entre 1 y 5 vieja: ";
        cin >> epsilon;
    }
    int min = 1, max = digito;
    size = getMeSize(digito);
    arr = simplificacion(digito, size);
    impresion(arr, size);
    double res = raizCuadrada(arr, size, (double)digito, (double)epsilon, (double)min, (double)max);
    cout << "\nLa raiz Generada de " << digito << " es: " << res << "\n";
    guardarArchivo(digito, res);
    return 0;
}