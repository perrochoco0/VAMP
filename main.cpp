#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Estructura para representar puntos en el plano (coordenadas x, y)
struct Punto {
    long double x;
    long double y;
};

// Función para calcular la distancia total del haz (Filamento -> Espejo -> Punto de Medición)
long double calcular_recorrido_haz(Punto f, Punto m, Punto p) {
    long double fm = sqrt(pow(m.x - f.x, 2) + pow(m.y - f.y, 2));
    long double mp = sqrt(pow(p.x - m.x, 2) + pow(p.y - m.y, 2));
    return fm + mp;
}

int main(){
    // Constante de la longitud de onda del láser (532 nm en metros)
    const long double longitud_onda = 532 * pow(10, -9);

    cout << "=== SISTEMA DE CALCULO - COMPETENCIA DE PELO (DIFRACCION) ===" << endl;

    // Configuración geométrica
    Punto filamento = {0.0, 0.0};          // Origen
    Punto punto_medicion = {0.0, 0.1};     // 10 cm (0.1 m) sobre el filamento

    Punto espejo;
    espejo.y = 0.0;                        // Misma altura vertical que el láser

    cout << "\n--- Configuracion del Espejo ---" << endl;
    cout << "Ingrese la distancia horizontal (posicion X) del espejo respecto al laser (en metros): ";
    cin >> espejo.x;

    // Cálculo de la distancia total del haz (L)
    long double L = calcular_recorrido_haz(filamento, espejo, punto_medicion);

    // Ingreso de las distancias entre mínimos simétricos para los dos primeros mínimos
    long double D1, D2;
    cout << "\n--- Medicion de Minimos Simetricos ---" << endl;
    cout << "Ingrese la distancia total entre el minimo -1 y +1 (D1 en metros): ";
    cin >> D1;
    cout << "Ingrese la distancia total entre el minimo -2 y +2 (D2 en metros): ";
    cin >> D2;

    // Cálculo del grosor del pelo (a) para cada caso:
    // a = (2 * m * lambda * L) / D_m
    // Para m = 1: D1 es la distancia entre -1 y +1
    // Para m = 2: D2 es la distancia entre -2 y +2
    long double grosor_1 = (2.0 * 1.0 * longitud_onda * L) / D1;
    long double grosor_2 = (2.0 * 2.0 * longitud_onda * L) / D2;
    long double grosor_promedio = (grosor_1 + grosor_2) / 2.0;

    // Resultados detallados
    cout << "\n----------------------------------------" << endl;
    cout << "          RESULTADOS FINALES            " << endl;
    cout << "----------------------------------------" << endl;
    cout << "Longitud de onda (lambda): " << longitud_onda << " m (532 nm)" << endl;
    cout << "Distancia total del haz (L): " << L << " m" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Primer minimo simetrico (m = 1):" << endl;
    cout << "  - Distancia D1: " << D1 << " m" << endl;
    cout << "  - Grosor calculado: " << grosor_1 * 1e6 << " um (" << grosor_1 << " m)" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Segundo minimo simetrico (m = 2):" << endl;
    cout << "  - Distancia D2: " << D2 << " m" << endl;
    cout << "  - Grosor calculado: " << grosor_2 * 1e6 << " um (" << grosor_2 << " m)" << endl;
    cout << "----------------------------------------" << endl;
    cout << "GROSOR PROMEDIO ESTIMADO: " << grosor_promedio * 1e6 << " um" << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}
