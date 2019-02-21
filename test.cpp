#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Store.h"
#include "Item.h"
#include "TextUI.h"
using namespace std;

ShoppingCart sc;
Item item1(0,"item1",5.00, 3);
Item item2(1,"item2",2.00,5);

TEST_CASE("DisplayCart","[shoppingCart]"){
	SECTION("empty"){		//if cart is empty, show empty display
		sc.ClearCart();
		REQUIRE(sc.DisplayCart()=="");
	}
	SECTION("addedItem"){		//check to see if added item is correctly displayed
		sc.AddItem(&item1);
		string one = sc.DisplayCart();
		vector<Item *> cart = sc.get_items();
		string inventory_ = "";
		for(Item* i: cart){
			inventory_.append(i->ToString());
			inventory_.append("\n");
		}
		REQUIRE(one == inventory_);
	}
}

TEST_CASE("addItem","[shoppingCart]"){
	SECTION("add to empty"){
		sc.ClearCart();
		vector<Item *> before = sc.get_items();
		REQUIRE(before.size()==0);
		sc.AddItem(&item1);
		before = sc.get_items();
		REQUIRE(before.size()==1);
	}

	SECTION("after add, remove from inventory"){
		int before = item1.get_quantity();
		sc.AddItem(&item1);
		int after = item1.get_quantity();
		REQUIRE(after == before+1);
	}
}

TEST_CASE("removeItem","[shoppingCart]"){
	SECTION("function"){		//item removed
		sc.AddItem(&item1);
		vector<Item *> before = sc.get_items();
		sc.RemoveItem(&item1);
		vector<Item *> after = sc.get_items();
		REQUIRE(before == after);
	}
}

TEST_CASE("ClearCart","[shoppingCart]"){
	SECTION("function"){
		sc.ClearCart();
		vector<Item *> empty_cart_ = sc.get_items();
		REQUIRE(empty_cart_.size()==0);
	}
}

// TEST_CASE("checkout","[store]"){
// 	Store s("")
// 	SECTION("add to empty")
// }

