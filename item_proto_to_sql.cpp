#include <iostream>
#include <fstream>
#include <string>
#include <tinyxml2.h>
#include <map>

using namespace tinyxml2;
using namespace std;

int main()
{
	XMLDocument doc;
	doc.LoadFile("item_proto.xml");
	// ItemProto ItemDef LocalizedName

    // const char* title = doc.FirstChildElement( "ItemProto" )->FirstChildElement()->Attribute( "LocalizedName" );
    // printf( "LocalizedName value = %s\n", title );

	map<string, string> itemAttributes {
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

	int elIndex = 0;
	for (const XMLElement* element = doc.FirstChildElement("ItemProto")->FirstChildElement(); element; element = element->NextSiblingElement("ItemDef")) {
		// if (elIndex == 105) {
		// 	break;
		// }

		map<string, string>::iterator i;
		for (i = itemAttributes.begin(); i != itemAttributes.end(); i++) {
			string attributeKey = element->Attribute(i->first);
			string attributeVal = element->Attribute(i->second);
			// write here all the stuff
		}

		// string LocalizedName = element->Attribute("LocalizedName");
		// item_proto_sql << "INSERT INTO item_proto (locale_name) VALUES (";
		// item_proto_sql << "\"" << LocalizedName << "\",";
		// item_proto_sql << ");\n";

		elIndex++;
	}
	item_proto_sql.close();
	// XMLTest("Crash bug parsing", 2, nProperty);

	return 0;
}
