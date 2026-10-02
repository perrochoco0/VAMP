#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;


long double media(vector<long double>resultados){
    // Calculo realizado con la media
    long double sumatoria = 0.0;
    for(int i = 0; i < resultados.size(); i++){
         sumatoria += resultados[i];
    }

    long double final_media = sumatoria/resultados.size();
    return final_media;
}


long double (vector<long double>resultados)

int main(){

    // Constante de la longitud de onda del laser
    const long double longitud = 560*pow(10,-9);

    // Definicéfinición báscia de variables
    long double resultado;
    vector<long double> mediciones_1(3);
    vector<long double> resultados;

    double medicion;
    for(int i = 0; i < 3; i++){
        cout<<"Insertar medición: ";
        cin>>medicion;
        mediciones_1[i] = medicion;
    }





    return 0;
}
