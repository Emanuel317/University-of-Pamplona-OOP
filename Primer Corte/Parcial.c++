#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool stringTypeVerification (string clientType);



int main () {

    bool repetition = true;
    while (repetition) {
        
        string clientType, hasCoDebtor;
        float loadAmount;
        int monthsNumber;    

        cout << "===== Banco Super Famoso de Colombia =====" << endl << endl;
        cout << "El siguiente programa le ayudará a determinar si un cliente cumple o no con las condiciones para solicitar un crédito de libre inversión,\n";
        cout << "En caso de cumplirlas, le entregará una proyección de la tasa de interés y el valor total a pagar. " << endl << endl;
        
        cout << "Ingrese el tipo de cliente que solicita el préstamo: " ;
        cin >> clientType;
        if (!stringTypeVerification(clientType)) {
            cout << "El tipo de dato ingresado no es válido. Por favor intenta nuevamente." << endl;
            repetition = false;
            break;
        }
        

    }
    return 0;
}






bool stringTypeVerification (string clientType) {

    transform(clientType.begin(), clientType.end(), clientType.begin(), ::toupper);

    if (clientType == "ESTUDIANTE" || clientType == "EMPLEADO" || clientType == "PENSIONADO" || clientType == "DESEMPLEADO") {
        return true;
    }

    return false;
}
