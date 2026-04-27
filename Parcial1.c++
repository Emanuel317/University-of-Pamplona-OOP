#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

//DefiniciÃ³n de Tasas de Interes
float rates[] = {0.06, 0.07, 0.04, 0.08};

bool stringTypeVerification (string stringValue);
bool floatTypeVerification (float floatValue);
bool intTypeVerification (int integerValue);
bool boolTypeVerification (bool booleanValue);
int loanValidation (string clientType, float loadAmount, int monthsNumber, bool hasCoDebtor);
void totalAmount (string clientType, float loadAmount, int monthsNumber, bool hasCoDebtor);


int main () {
	
	//Mensaje de inicio para la ejecuciÃ³n del programa 
	cout << "\t\t===== Banco Super Famoso de Colombia =====" << endl << endl;
	cout << "El siguiente programa le ayudarÃ¡ a determinar si un cliente cumple o no con las condiciones para solicitar un crÃ©dito de libre inversiÃ³n. En caso de cumplirlas, le entregarÃ¡ una proyecciÃ³n de la tasa de interÃ©s y el valor total a pagar. " << endl;
	cout << "========================================================================================================================" << endl << endl;
	cout << "========================================================================================================================" << endl;
	
	//InicializaciÃ³n del bucle del programa
	bool repetition = true;
	while (repetition) {
		
		//DeclaraciÃ³n de variables
		string clientType;
		float loadAmount;
		int monthsNumber;
		bool hasCoDebtor;
		char exit = 'N';
		
		//Ingreso de datos por parte del usuario y verificaciÃ³n de tipos y rangos
		cout << "Ingrese el tipo de cliente que solicita el prÃ©stamo: " ;
		cin >> clientType;
		
		transform(clientType.begin(), clientType.end(), clientType.begin(), ::toupper);
		if (!stringTypeVerification(clientType)) {
			continue;
		}
		
		cout << "Ingrese el monto del prÃ©stamo solicitado por el cliente: " ;
		cin >> loadAmount;
		if (!floatTypeVerification(loadAmount)) {
			continue;
		}
		
		cout << "Ingrese el plazo (en meses) para el pago total de las cuotas del prÃ©stamo: " ;
		cin >> monthsNumber;
		if (!intTypeVerification(monthsNumber)) {
			continue;
		}
		
		cout << "Ingrese si el cliente cuenta con un co-deudor vÃ¡lido para solicitar el prÃ©stamo [1/0]: " ;
		cin >> hasCoDebtor;
		if (!boolTypeVerification(hasCoDebtor)) {
			continue;
		}
		
		//AprobaciÃ³n o Rechazo del crÃ©dito socilitado
		int result = loanValidation(clientType, loadAmount, monthsNumber, hasCoDebtor);
		
		//Respuestas hacia el cliente
		cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
		switch(result){
			case 1:
				totalAmount(clientType, loadAmount, monthsNumber, hasCoDebtor);		//Por facilidades para escribir las tasas de interÃ©s se toma la decisiÃ³n de crear otra funciÃ³n
				break;
			case 2:
				cout << "\t\aRECHAZADO. El plazo excede el mÃ¡ximo de tiempo permitido para crÃ©ditos de montos bajos" << endl << endl;
				break;
			case 3:
				cout << "\t\aRECHAZADO. El plazo excede el mÃ¡ximo de tiempo permitido para crÃ©ditos de montos altos" << endl << endl;
				break;
			case 4:	
				cout << "\t\aRECHAZADO. El monto solicitado excede el lÃ­mite permitido con codeudor" << endl << endl;
				break;
			case 5:
				cout << "\t\aRECHAZADO. El monto solicitado excede el lÃ­mite permitido sin codeudor" << endl << endl;
				break;
			case 6:
				cout << "\t\aRECHAZADO. Si se encuentra en condiciÃ³n de desempleo, debe tener un codeudor que soporte responsabilidad por el crÃ©dito solicitado" << endl << endl;
				break;
			default:
				cout << "\t\aCaso por defecto del switch que no deberÃ­a aparecer en la consola" << endl << endl;
		}
		
		//ConfirmaciÃ³n para seguir ejecutando o finalizar el programa
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\tÂ¿Desea salir del programa? [S/N] ";
		cin >> exit;
		repetition = (exit == 'S') ? false : true;
		cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	
	return 0;
}




//DeclaraciÃ³n de Funciones MUY Ãštiles

//VerificaciÃ³n de Tipo String
bool stringTypeVerification (string clientType) {
	
	if (clientType == "ESTUDIANTE" || clientType == "EMPLEADO" || clientType == "PENSIONADO" || clientType == "DESEMPLEADO") {
		return true;
	} else {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tipo de dato ingresado no es vÃ¡lido, recuerde que solo se admite [Estudiante/Empleado/Pensionado/Desempleado]. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}

//VerificaciÃ³n de Tipo Float
bool floatTypeVerification (float loadAmount) {
	
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tipo de dato ingresado no es vÃ¡lido, recuerde que solo se admite montos entre 1000 - 99999999. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
	
	if (loadAmount > 1000 && loadAmount < 99999999) {
		return true;
	} else {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tamaÃ±o del dato ingresado no es vÃ¡lido, recuerde que solo se admite montos entre 1000 - 99999999. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}

//VerificaciÃ³n de Tipo Integer
bool intTypeVerification (int monthsNumber) {
	
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tipo de dato ingresado no es vÃ¡lido, recuerde que solo se admite entre 2 - 50 meses. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
	
	if (monthsNumber > 1 && monthsNumber < 50) {
		return true;
	} else {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tamaÃ±o del dato ingresado no es vÃ¡lido, recuerde que solo se admite entre 2 - 50 meses. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}

//VerificaciÃ³n de Tipo Booleano
bool boolTypeVerification (bool hasCoDebtor) {
	
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tipo de dato ingresado no es vÃ¡lido, recuerde que solo se admite [1 = Si, 0 = No]. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return hasCoDebtor = false;
	}

	return hasCoDebtor = true;
}


/*ValidaciÃ³n del CrÃ©dito
Para efectos prÃ¡cticos y mejor lectura del cÃ³digo, se plantean las siguientes salidas:
1. Resultado satisfactorio para la aprobaciÃ³n del crÃ©dito CON o SIN co-deudor
2. Rechazo por exceso en el lÃ­mite de tiempo de pago para crÃ©ditos grandes
3. Rechazo por exceso en el lÃ­mite de tiempo de pago para crÃ©ditos pequeÃ±os
4. Rechazo por exceso en el lÃ­mite de monto permitido para el crÃ©dito CON co-deudor
5. Rechazo por exceso en el lÃ­mite de monto permitido para el crÃ©dito SIN co-deudor
6. Rechazo de cliente desempleado por no tener co-deudor*/

int loanValidation (string clientType, float loadAmount, int monthsNumber, bool hasCoDebtor) {
	
	if (clientType == "ESTUDIANTE") {
		if (hasCoDebtor == true) {
			if (loadAmount > 5000000) return 4;
				if (monthsNumber > 24) return 2;
					return 1;
				
		} else {
			if (loadAmount > 2000000) return 5;
				if (monthsNumber > 12) return 3;
					return 1;
		}
	}
	
	if (clientType == "EMPLEADO") {
		if (hasCoDebtor == true) {
			if (loadAmount > 10000000) return 4;
				if (monthsNumber > 48) return 2;
					return 1;
			
		} else {
			if (loadAmount > 5000000) return 5;
				if (monthsNumber > 24) return 3;
					return 1;
		}
	}
	
	if (clientType == "PENSIONADO") {
		if (hasCoDebtor == true) {
			if (loadAmount > 7000000) return 4;
				if (monthsNumber > 48) return 2;
					return 1;
			
		} else {
			if (loadAmount > 3000000) return 5;
				if (monthsNumber > 24) return 3;
					return 1;
		}
	}
	
	if (clientType == "DESEMPLEADO") {
		if (hasCoDebtor == true) {
			if (loadAmount > 2000000) return 4;
				if (monthsNumber > 12) return 3;
					return 1;
			
		} else {
			return 6;
		}
	}
	
	return 6;
}

//Calculo del Monto Total (e ImpresiÃ³n en la consola por facilidad)
//MODIFICACIONES EN CLASE
void totalAmount (string clientType, float loadAmount, int monthsNumber, bool hasCoDebtor) {
	
	float interestRate = (clientType == "ESTUDIANTE") ? *(rates + 0) : (clientType == "EMPLEADO") ? *(rates + 1) : (clientType == "PENSIONADO") ? *(rates + 2) : (clientType == "DESEMPLEADO") ? *(rates + 3) : 1;
	
	//A) Si el plazo es mayor a 36 meses, incrementar tasa en 1.5%
	if (monthsNumber > 36) {
		interestRate += 0.015;
	}
	
	float loadInterest = loadAmount * interestRate * monthsNumber;
	
	//Si el cliente es "Empleado" o "Pensionado" y tiene codeudor, aplicar un descuento del 10% sobre el interés calculado
	if ((clientType == "EMPLEADO" && hasCoDebtor) || (clientType == "PENSIONADO" && hasCoDebtor)) {
		loadInterest -= loadInterest * 0.1;
	}
	
	float totalAmount = loadAmount + loadInterest;
	
	cout << "\tEl préstamo solicitado por un monto de $" << fixed << setprecision(2) << loadAmount << " a un plazo de " << monthsNumber << " meses se considera APROBADO con una Tasa del " << setprecision(1) << interestRate * 100 << "%" << endl;
	cout << "\tTotal a pagar: $ " << setprecision(2) << totalAmount << endl << endl;
}
