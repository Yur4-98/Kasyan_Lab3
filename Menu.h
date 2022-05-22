#pragma once
#include "Tree.h"
#include "People.h"

#include "Complex.h"
#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

template <typename T>
T mult2(T t) {

	return t * 2;
}
template <typename T>
bool ch5(T t) {
	return t > 5;
}

void print_menu0() {
	system("cls");
	cout << "What is the type of variables in the tree?" << endl;
	cout << "1. Int" << endl;
	cout << "2. Float" << endl;
	cout << "3. Complex" << endl;
	cout << "4. String" << endl;
	cout << "5. People" << endl;
	cout << ">";
}

template <typename T>
void print_menu(DynamicArray<T> arr) {
	system("cls");
	cout << "number of trees: " << arr.GetSize() << endl;
	cout << "1. Create new tree(empty)" << endl;
	cout << "2. Insert element in tree" << endl;
	cout << "3. remove element from tree" << endl;
	cout << "4. map" << endl;
	cout << "5. where" << endl;
	cout << "6. Get subtree using element" << endl;
	cout << "7. Merge 2 trees" << endl;
	cout << "8. find node" << endl;
	cout << "9. find subtree" << endl;
	cout << "10. Print the tree as order" << endl;
	cout << "11. New Tree from array" << endl;
	cout << "12. Print tree" << endl;
	cout << "13. Exit" << endl;
	cout << ">";
}

void print_choose_tree() {
	cout << "What tree we use?" << endl;

	cout << ">";
}

void print_choose_order() {
	cout << "What order?" << endl;
	cout << "1. KLP" << endl;
	cout << "2. KPL" << endl;
	cout << "3. LPK" << endl;
	cout << "4. LKP" << endl;
	cout << "5. PLK" << endl;
	cout << "6. PKL" << endl;
	cout << ">";
}

int get_variant(int count) {
	int variant = 0;
	//string s;
	//getline(cin, s);

	do
	{
		cin >> variant;
		if (variant < 1 || variant > count)
		{
			cout << "Incorrec input. Try again: ";
		}
	} while (variant < 1 || variant > count);

	
	/*
	while (sscanf_s(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
		cout << "Incorrec input. Try again: ";
		getline(cin, s);
	}
	*/
	return variant;
}
template <typename T>

void new_tree(DynamicArray<Tree<T>*> *arr) {
	Tree<T>* tr = new Tree<T>;
	(*arr).Append(tr);
}
template <typename T>
void insert(DynamicArray<Tree<T>*>* arr) {
	print_choose_tree();
	T data;
	int var = 0;
	var = get_variant(arr->GetSize())-1;
	cout << "Enter a new element" << endl;
	cout << ">";
	cin >> data;
	(*arr)[var]->Insert(data);
}
template <typename T>
void remove(DynamicArray<Tree<T>*>* arr) {
	print_choose_tree();
	T data;
	int var = 0;
	var = get_variant(arr->GetSize())-1;
	cout << "Enter the item to delete" << endl;
	cout << ">";
	cin >> data;
	(*arr)[var]->Remove(data);
}
template <typename T>
void map(DynamicArray<Tree<T>*>* arr) {
	print_choose_tree();
//	T (*func)(T);
//	func = mult2;
	int var = 0;
	var = get_variant(arr->GetSize())-1;
	cout << "Now is mult to 2" << endl;
//	cin >> data;

	(*arr).Append((*arr)[var]->Map(mult2));

}
template <typename T>
void where(DynamicArray<Tree<T>*>* arr) {
	print_choose_tree();
//	bool (*func)(T x);
//	func = ch5;
	int var = 0;
	var = get_variant(arr->GetSize())-1;
	cout << "Now is >5" << endl;
	//	cin >> data;
	(*arr).Append((*arr)[var]->Where(ch5));

}
/*
template <typename T>
void little_tree(DynamicArray<Tree<T>*>* arr) {
	print_choose_tree();
	T data;
	int var = 0;
	var = get_variant(arr->GetSize());
	cout << "¬ведите корень искомого поддерева" << endl;
	cout << ">";
	cin >> data;
	

	Tree<T>* tr = new Tree<T>;
	(*arr)[var]->NewTree(data);
	(*arr).Append(tr);
}*/

template <typename T>
void get_subtree_using_element(DynamicArray<Tree<T>*>* arr) {
	print_choose_tree();
	int var = 0;
	T data;
	var = get_variant(arr->GetSize()) - 1;
	cout << "Enter root of new tree" << endl;
	cout << ">";
	cin >> data;
	Tree<T>* tr = (*arr)[var]->NewTree(data);
	(*arr).Append(tr);
}

template <typename T>
void merge_trees(DynamicArray<Tree<T>*>* arr) {
	print_choose_tree();
	int var1 = 0, var2 = 0;
	var1 = get_variant(arr->GetSize()) - 1;
	print_choose_tree();
	var2 = get_variant(arr->GetSize()) - 1;

	Tree<T>* tr = (*arr)[var1]->merge((*arr)[var2]);
	(*arr).Append(tr);
}

template <typename T>
void find_node(DynamicArray<Tree<T>*>* arr) {
	print_choose_tree();
	T data;
	int var = 0;
	var = get_variant(arr->GetSize())-1;
	cout << "Enter the element to be checked" << endl;
	cout << ">";
	cin >> data;
	if ((*arr)[var]->Find(data))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	
}
template <typename T>
void find_tree(DynamicArray<Tree<T>*>* arr) {
	print_choose_tree();
	int var1 = 0, var2 = 0;
	var1 = get_variant(arr->GetSize())-1;
	print_choose_tree();
	var2 = get_variant(arr->GetSize())-1;
	if ((*arr)[var1]->FindTree(*((*arr)[var2])))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}
template <typename T>
void Print_Tree_as_arr(DynamicArray<Tree<T>*>* arr) {
	print_choose_tree();
	int var1 = 0;
	var1 = get_variant(arr->GetSize())-1;
	print_choose_order();
	int var2 = 0;
	var2 = get_variant(6);
	DynamicArray<T> ar;
	switch (var2)
	{
	case 1:
		ar = (*arr)[var1]->PreOrder();
		ar.Print();
		break;
	case 2:
		ar = (*arr)[var1]->Order4();
		ar.Print();
		break;
	case 3:
		ar = (*arr)[var1]->PostOrder();
		ar.Print();
		break;
	case 4:
		ar = (*arr)[var1]->InOrder();
		ar.Print();
		break;
	case 5:
		ar = (*arr)[var1]->Order5();
		ar.Print();
		break;
	case 6:
		ar = (*arr)[var1]->Order6();
		ar.Print();
		break;
	}
}
template <typename T>
void get_tree_from_arr(DynamicArray<Tree<T>*>* arr) {//
	
	cout << "Enterring of array:" << endl;
	cout << "How many elements in array?" << endl;
	int n;
	cin >> n;
	T data;
	Tree<T>* tr = new Tree<T>;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		tr->Insert(data);

	}
	(*arr).Append(tr);
}
template <typename T>
void print_tree(DynamicArray<Tree<T>*>* arr) {
	print_choose_tree();
	int var = 0;
	var = get_variant(arr->GetSize())-1;

	(*arr)[var]->Print();
}

template <typename T>
void menu3(DynamicArray<Tree<T>*>* arr) {
	int var = 12;
	do
	{

		print_menu(*arr);
		var = get_variant(12);
		switch (var)
		{
		case 1:
			new_tree(arr);
			break;
		case 2:
			insert(arr);
			break;
		case 3:
			remove(arr);
			break;
		
			//		case 6:
			//			
			//			break;
		case 7:
			find_node(arr);
			break;
		case 8:
			find_tree(arr);
			break;
		case 9:
			Print_Tree_as_arr(arr);
			break;
		case 10:
			get_tree_from_arr(arr);
			break;
		case 11:
			print_tree(arr);
			break;
		}
		if (var != 12)
			system("pause");
	} while (var != 12);

}

template <typename T>
void menu1 ( DynamicArray<Tree<T>*> *arr){
	int var = 12;
	do
	{

		print_menu(*arr);
		var = get_variant(13);
		switch (var)
		{
		case 1:
			new_tree(arr);
			break;
		case 2:
			insert(arr);
			break;
		case 3:
			remove(arr);
			break;
		case 4:
			map(arr);//проблема строки
			break;
		case 5:
			where(arr);//проблема строки
			break;
		case 6:
			get_subtree_using_element(arr);
			break;
		case 7:
			merge_trees(arr);
			break;
		case 8:
			find_node(arr);
			break;
		case 9:
			find_tree(arr);
			break;
		case 10:
			Print_Tree_as_arr(arr);
			break;
		case 11:
			get_tree_from_arr(arr);
			break;
		case 12:
			print_tree(arr);
			break;
		}
	
		if (var != 13)
			system("pause");
	} while (var != 13);
	
}

void menu() {
	
	DynamicArray<Tree<int>*> arr1;
	DynamicArray<Tree<float>*> arr2;
	DynamicArray<Tree<Complex>*> arr3;
	DynamicArray<Tree<string>*> arr4;// map/where
	DynamicArray<Tree<People>*> arr5;//перегрузить операторы
	int var = 0;

	print_menu0();
	var = get_variant(5);
	switch (var)
	{
	case 1:
		menu1(&arr1);
		break;
	case 2:
		menu1(&arr2);
		break;
	case 3:
		menu1(&arr3);
		break;
	case 4:
		menu3(&arr4);
		break;
	case 5:
		menu1(&arr5);
		break;
	}
}