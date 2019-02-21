#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Store.h"
#include "Item.h"
#include "TextUI.h"
using namespace std;

ShoppingCart sc;
Store s("store.txt");

vector<Item *> inventory = s.get_inventory();

TEST_CASE("DisplayCart","[shoppingCart]"){
	SECTION("empty"){		//if cart is empty, show empty display
		sc.ClearCart();
		REQUIRE(sc.DisplayCart()=="");
	}
	SECTION("addedItem"){		//check to see if added item is correctly displayed
		sc.AddItem(inventory[0]);
		string one = sc.DisplayCart();
		vector<Item *> cart = sc.get_items();
		string inventory_ = "";
		for(Item* i: cart){
			inventory_.append(i->ToString());
			inventory_.append("\n");
		}
		REQUIRE(one = inventory_);
	}
}

TEST_CASE("addItem","[shoppingCart]"){
	SECTION("function"){
		vector<Item *> before = sc.get_items();
		sc.AddItem(inventory[1]);
		vector<Item *> after = sc.get_items();
		REQUIRE(before != after);
	}

	SECTION("after add, remove from inventory"){
		int before = inventory[0]->get_quantity();
		sc.AddItem(inventory[0]);
		int after = inventory[0]->get_quantity();
		REQUIRE(after = before+1);
	}
}

TEST_CASE("removeItem","[shoppingCart]"){
	SECTION("function"){		//item removed
		sc.AddItem(inventory[0]);
		vector<Item *> before = sc.get_items();
		sc.RemoveItem(inventory[0]);
		vector<Item *> after = sc.get_items();
		REQUIRE(before == after);
	}
}

TEST_CASE("ClearCart","[shoppingCart]"){
	SECTION("function"){
		sc.ClearCart();
		vector(Item *) empty_cart_ = sc.get_items();
		REQUIRE(empty_cart_.size()==0);
	}
}

