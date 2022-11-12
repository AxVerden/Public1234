#pragma once
#include <iostream>
#include "Field.h"

using namespace std;


class Controller
{
public:
	Controller()
	{
		field.generate_field(6);
		field.show_field();
	}

	void move()
	{
		while (choice != 9)
		{
			cout << "Let's Play!!!!" << endl;
			cout << "1) Start Playing\n" << "2) Choose entity\n" << "9) Exit\n" << endl;
			cout << "Enter choice: ";
			cin >> choice;
			if (choice == 1)
			{
				while (choice_2 != 8)
				{
					cout << "To continue enter any key, for exit enter 8: " << endl;
					cin >> choice_2;
					if (choice_2 == 8)
					{
						break;
					}
					cout << endl;
					cout << "Enter x: ";
					cin >> x;
					cout << "Enter y: ";
					cin >> y;
					if ((x < 0 || y < 0) || (y > 5 || x > 5)) {
						cout << "Error" << endl;
						continue;
					}
					else if ((tmp_x + 1 == x && tmp_y == y) || (tmp_x - 1 == x && tmp_y == y) || (tmp_x == x && tmp_y + 1 == y) || (tmp_x == x && tmp_y - 1 == y)) {
						field.set_xy(x, y, entity_type);
						field.show_field();
						tmp_x = x;
						tmp_y = y;
					}
				}
 			}

			else if (choice == 2)
			{
				char c;
				while (true) {
					field.show_field();
					cout << "Enter coordinate animal what you desired: ";
					cout << "X = ";
					cin >> x;
					cout << "Y = ";
					cin >> y;
					entity_type = field.choosing_an_animal(x, y);
					if (entity_type.c_str()[0] == '$') {
						cout << "Wrong chosing coordinates" << endl;
					}
					else {
						field.setTmp_x(x);
						field.setTmp_y(y);
						tmp_x = x;
						tmp_y = y;
						field.show_field();
						cout << entity_type << endl;
						break;
					}

				}
				
			}

			else if (choice == 9)
			{
				cout << "Exiting....." << endl;
				break;
			}
		}
	}



private:
	int choice;
	int choice_2;
	int x,tmp_x;
	int y,tmp_y;
	string entity_type;
	Field field;
	Predator pred;
	Herbivores herb;
};

