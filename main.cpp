#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

void add_item(Item *item_list, double price, const char *sku,
              const char *category, const char *name, int index) {
    item_list[index].price = price;

		item_list[index].sku = new char[strlen(sku) + 1];
		strcpy(item_list[index].sku, sku);

		item_list[index].name = new char[strlen(name) + 1];
    strcpy(item_list[index].name, name);

		item_list[index].category = new char[strlen(category) + 1];
		strcpy(item_list[index].category, category);
		
		}

void free_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
		    delete[] item_list[i].sku;
        delete[] item_list[i].name;
        delete[] item_list[i].category;
		}
		delete[] item_list;
	}

double average_price(Item *item_list, int size) {
    double sum = 0.0;
		for (int i = 0; i < size; i++) {
				sum += item_list[i].price;
		}
		return sum / size;
	}

	void print_items(Item *item_list, int size) {
	    for (int i = 0; i < size; i++) {
			        cout << "###############" << endl;
			        cout << "item name = " << item_list[i].name << endl;
							cout << "item sku = " << item_list[i].sku << endl;
							cout << "item category = " << item_list[i].category << endl;
							cout << "item price = " << item_list[i].price << endl;
			}
	}

int main(int argc, char *argv[]) {
    int size = 5;
		Item *item_list = new Item[size];
		
		add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
		add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
		add_item(item_list, 7.85, "14512", "snack", "chips", 2);
		add_item(item_list, 9.45, "53421", "meat", "steak", 3);
		add_item(item_list, 4.95, "90213", "produce", "apples", 4);
			 
		if (argc > 1) {
				char *sku = argv[1];
				int ct = 0;

				while (ct < size && strcmp(item_list[ct].sku, sku) != 0) {
	  	    ct++;
				}

				if (ct < size) {
					cout << "###############" << endl;
					cout << "Found item:" << endl;
					cout << "item name = " << item_list[ct].name << endl;
					cout << "item sku = " << item_list[ct].sku << endl;
					cout << "item category = " << item_list[ct].category << endl;
					cout << "item price = " << item_list[ct].price << endl;

				} else {
					cout << "Item not found" << endl;
				}
		}
		else {
				print_items(item_list,size);
				cout << "average price of items = " << average_price(item_list,size) << endl;
		}

		free_items(item_list, size);
		return 0;
}










