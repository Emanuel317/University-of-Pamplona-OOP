#include <iostream>

/**
 * Implementación del Doxygen
 * @brief Programa en C++ que modela una jerarqu+ia de equipos y jugadores de fútbol
 * @param 
 * @return No retorna nada
 */

using std::string;

class SoccerTeam {
    private:
        string teamName;

    protected:
        int seasonPoints;

        void setTeamName (string teamName) {
            this->teamName = teamName;
        }

        string getTeamName () {
            return this->teamName;
        }

        void setSeasonPoints (int seasonPoints) {
            this->seasonPoints = seasonPoints;
        }

        int getSeasonPoints () {
            return this->seasonPoints;
        }
};


int main () {


    return 0;
}