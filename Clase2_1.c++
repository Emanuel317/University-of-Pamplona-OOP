#include <iostream>

/**
 * Implementación del Doxygen
 * @brief Programa en C++ que modela una jerarqu+ia de equipos y jugadores de fútbol
 * @param 
 * @return No retorna nada
 */

using std::string;

// Clase base que representa a un equipo de fútbol
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


// Clase hija que representa a un jugador de fútbol
class SoccerPlayer : public SoccerTeam {
    private:
        string playerName;
        int goalsScored;
        int position;

    public:
        void setPlayerName (string playerName) {
            this->playerName = playerName;
        }

        string getPlayerName () {
            return this->playerName;
        }

        void setGoalsScored (int goalsScored) {
            this->goalsScored = goalsScored;
        }

        int getGoalsScored () {
            return this->goalsScored;
        }

        void setPosition (int position) {
            this->position = position;
        }

        int getPosition () {
            return this->position;
        }
};


//Clase hija que representa a un entrenador de fútbol
class SoccerCoach : public SoccerTeam {
    private:
        string coachName;
        int yearsOfExperience;

    public:
        void setCoachName (string coachName) {
            this->coachName = coachName;
        }

        string getCoachName () {
            return this->coachName;
        }

        void setYearsOfExperience (int yearsOfExperience) {
            this->yearsOfExperience = yearsOfExperience;
        }

        int getYearsOfExperience () {
            return this->yearsOfExperience;
        }
};


int main () {


    return 0;
}