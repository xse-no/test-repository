#include <iostream>
#include <string>


class student {
	friend class teacher;
private:
	unsigned int _lastRate;
	float _avarageRating;
	short int _satiety = 0;
	short int _thirst = 0;
	short int _mood = 0;
	static unsigned int NOS; // NOS - Number Of Students

public:

	void getStats() {
		std::cout << "Голод :" << _satiety << "/1000" << std::endl
		<< "Жажда :" << _thirst << "/1000" << std::endl
		<< "Настроение :" << _mood << "/1000" << std::endl
		<< "\nПоследняя оценка :" << _lastRate << "/5" << std::endl
		<< "Средняя оценка :" << _avarageRating << "/5" << std::endl;
	}

	void limits(short int& value, short int lowerLimit, short int upperLimit) {
		if (value < lowerLimit) { value = lowerLimit; }
		else if (value > upperLimit) { value = upperLimit; }
	}

	void feed() {
		_satiety -= 50 + (int(rand()) % 250);
		_thirst -= (rand() % 150);
		_mood += (rand() % 130);

		limits(_satiety, 0, 1000);
		limits(_thirst, 0, 1000);
		limits(_mood, 0, 1000);
	}

	void getDrunk() {
		_satiety -= (rand() % 140);
		_thirst -= 50 + (int(rand()) % 300);
		_mood += (rand() % 90);

		limits(_satiety, 0, 1000);
		limits(_thirst, 0, 1000);
		limits(_mood, 0, 1000);
	}

	void letPlay() {
		_satiety += (int(rand()) % 140);
		_thirst += (int(rand()) % 180);
		_mood += (rand() % 300);

		limits(_satiety, 0, 1000);
		limits(_thirst, 0, 1000);
		limits(_mood, 0, 1000);
	}



	student() {
		NOS++;
		int rate = (unsigned short int)rand() % 4 + 2;
		_lastRate = rate;
		_avarageRating = rate;
	}

};
unsigned int student::NOS = 0;


class teacher {
public:
	void setRate(student& stud) {
		unsigned short int rate = (unsigned short int)rand() % 4 + 2;
		stud._lastRate = rate;
		stud._avarageRating = (stud._avarageRating + rate) / 2;
	}
};


int main() {
	setlocale(LC_ALL, "ru");
	teacher zerganov;
	student evgeha;
	int choise;

	zerganov.setRate(evgeha);

	while (true) {
		evgeha.getStats();
		std::cout << std::endl;
		std::cout << "1 - дать поиграть, 2 - накормить, 3 - напоить, 4 - отправить на урок" << std::endl;
		std::cin >> choise;
		switch (choise) {
		case 1:
			evgeha.letPlay();
			std::cout << "Он(-а) поиграл(-а)!" << std::endl;
			break;

		case 2:
			evgeha.feed();
			std::cout << "Он(-а) поел(-а)!" << std::endl;
			break;

		case 3:
			evgeha.getDrunk();
			std::cout << "Он(-а) попил(-а)!" << std::endl;
			break;

		case 4:
			zerganov.setRate(evgeha);
			std::cout << "Он(-а) сходил(-а) на урок!" << std::endl;
			break;

		default:
			break;
		}
	}
	return 0;
}