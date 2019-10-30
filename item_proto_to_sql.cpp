#include <iostream>
#include <fstream>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>

using namespace tinyxml2;
using namespace std;

int main()
{
	XMLDocument doc;
	doc.LoadFile("item_proto.xml");

	unordered_map<string, string> itemAttributes {
		{"Vnum", "vnum"},
		{"Name", "name"},
		{"LocalizedName", "locale_name"},
		{"Type", "type"},
		{"SubType", "subtype"},
		{"Weight", "weight"},
		{"Size", "size"},
		{"AntiFlags", "antiflag"},
		{"Flags", "flag"},
		{"WearFlags", "wearflag"},
		{"ImmuneFlags", "immuneflag"},
		{"Gold", "gold"},
		{"ShopBuyPrice", "shop_buy_price"},
		{"LimitType0", "limittype0"},
		{"LimitValue0", "limitvalue0"},
		{"LimitType1", "limittype1"},
		{"LimitValue1", "limitvalue1"},
		{"ApplyType0", "applytype0"},
		{"ApplyValue0", "applyvalue0"},
		{"ApplyType1", "applytype1"},
		{"ApplyValue1", "applyvalue1"},
		{"ApplyType2", "applytype2"},
		{"ApplyValue2", "applyvalue2"},
		{"Value0", "value0"},
		{"Value1", "value1"},
		{"Value2", "value2"},
		{"Value3", "value3"},
		{"Value4", "value4"},
		{"Value5", "value5"},
		{"Socket0", "socket0"},
		{"Socket1", "socket1"},
		{"Socket2", "socket2"},
		{"RefinedVnum", "refine_vnum"},
		{"RefineSet", "refine_set"},
		{"AlterToMagicItemPercent", "magic_pct"},
		{"Specular", "specular"},
		{"GainSocketPercent", "socket_pct"},
		{"AddonType", "addon_type"}
	};

	ofstream item_proto_sql;
	item_proto_sql.open("item_proto.sql");


	for (const XMLElement* element = doc.FirstChildElement("ItemProto")->FirstChildElement(); element; element = element->NextSiblingElement("ItemDef")) {

		// INSERT Begin
		item_proto_sql << "INSERT INTO item_proto (";

		for (auto i = itemAttributes.begin(); i != itemAttributes.end(); ++i) {
			item_proto_sql << "\"" << i->second << "\"";
			if (next(i) != itemAttributes.end()) {
				item_proto_sql << ",";
			}
		}

		item_proto_sql << ") VALUES (";
		for (auto j = itemAttributes.begin(); j != itemAttributes.end(); ++j) {
			// write here all the stuff
			item_proto_sql << "\"" << element->Attribute(j->first.c_str()) << "\"";
			if (next(j) != itemAttributes.end()) {
				item_proto_sql << ",";
			}
		}

		// INSERT End
		item_proto_sql << ");\n";
	}
	item_proto_sql.close();

	return 0;
}
