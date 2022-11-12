#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Herbivores.h"
#include "Plants.h"
#include "Predator.h"
#pragma once
using namespace std;
#define M 5
#define N 5


class Field
{
public:
	void generate_field(int amount)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				v.push_back("_");
			}
			matrix.push_back(v);
		}

		//filing_field

		count_a = 0;
		bool flag = false;
		while (count_a != amount+1)
		{
			// Сделать так чтобы не повторялись значения из функции rand();
			random_generation_xy(i_coordinates, j_coordinates); // Генерация 
			random_generation_type(ptype);
			for (auto& a : predator_vector) {
				if (a.get_x() == i_coordinates && a.get_y() == j_coordinates) {
					flag = true;
				}
			}
			for (auto& a : plants_vector) {
				if (a.get_x() == i_coordinates && a.get_y() == j_coordinates) {
					flag = true;
				}
			}
			for (auto& a : herbivores_vector) {
				if (a.get_x() == i_coordinates && a.get_y() == j_coordinates) {
					flag = true;
				}
			}
			if (flag) {
				flag = false;
				continue;
			}
			if (ptype == 1)
			{
				cat.set_x(i_coordinates);
				cat.set_y(j_coordinates);
				predator_vector.push_back(cat); // Добавляем саму сущность в вектор
				matrix[i_coordinates][j_coordinates] = "C";
			}
			else if (ptype == 2)
			{
				mouse.set_x(i_coordinates);
				mouse.set_y(j_coordinates);
				herbivores_vector.push_back(mouse);
				matrix[i_coordinates][j_coordinates] = "M";
			}
			else if (ptype == 3)
			{
				grass.set_x(i_coordinates);
				grass.set_y(j_coordinates);
				plants_vector.push_back(grass);
				matrix[i_coordinates][j_coordinates] = "G";

			}
			count_a += 1;
			cout << "Counter = " << count_a << "\tX_coordinate = " << i_coordinates << "\tY_coordinate = " << j_coordinates << "\ttype = " << ptype << endl;

		}

	}

	
	char choosing_an_animal(int x, int y) {
		for (auto& a : predator_vector) {
			if (a.get_x() == x && a.get_y() == y) {
				return 'C';
			}
		}
		for (auto& b : herbivores_vector) {
			if (b.get_x() == x && b.get_y() == y) {
				return 'M';
			}
		}
		return '$';
	}

	void show_field()
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
	}

	void amount_xy_of_field(int& amount_x, int& amount_y)
	{
		amount_x = N;
		amount_y = M;
	}

	void set_xy(int x, int y, string type)
	{
		matrix[tmp_x][tmp_y] = "_";
		matrix[x][y] = type;
		tmp_x = x;
		tmp_y = y;
	}

	void setTmp_x(int x) {
		tmp_x = x;
	}
	void setTmp_y(int y) {
		tmp_y = y;
	}

	void random_generation_xy(int& coordinates_x, int& coordinates_y)
	{
		srand(time(NULL));
		coordinates_x = rand() % N;
		coordinates_y = rand() % N;
	}

	void random_generation_type(int& ptype)
	{
		srand(time(NULL));
		ptype = (rand() % 3) +1;
	}


private:
	string value_entity;
	vector<vector<string>> matrix;
	vector<string> v;
	int* coordinates_x;
	int* coordinates_y;
	int count_a;
	int i_coordinates;
	int j_coordinates;
	int number_of_entity;
	int ptype;
	int type_of_entity;
	int x;
	int y;
	int tmp_x;
	int tmp_y;
	string type;

protected:
	vector<vector<int>> region_place;
	vector <Herbivores> herbivores_vector;
	vector <Predator> predator_vector;
	vector <Plants> plants_vector;

	Herbivores mouse;
	Predator cat;
	Plants grass;
};