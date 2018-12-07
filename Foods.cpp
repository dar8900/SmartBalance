#include"Foods.h"

#undef ERASE_ALL

#ifndef ERASE_ALL
const NUTRITIONAL_VALUES NutritionalTableFruits[] = 
{
	{"Mela"							,52},
	{"Ananas"						,55},
	{"Albicocca"					,43},
	{"Pera"							,55},
	{"Banana"						,88},
	{"Mirtilli"						,35},
	{"Arancia rossa"				,45},
	{"More"							,43},
	{"Mirtilli rossi"				,46},
	{"Fragole"						,32},
	{"Fico"							,107},
	{"Pompelmo"						,50},
	{"Melograno"					,74},
	// {"Rosa canina"					,162},
	{"Melone"						,54},
	{"Lamponi"						,36},
	{"Zenzero"						,80},
	{"Kiwi"							,51},
	{"Ciliegie"						,50},
	// {"Litchi"						,66},
	{"Mandarino"					,50},
	{"Mango"						,62},
	// {"Maracuja"						,97},
	{"Prugna"						,47},
	{"Pesca"						,41},
	// {"Mela cotogna"					,38},
	// {"Rabarbaro"					,21},
	{"Anguria"						,30},
	{"Uva"							,70},
	{"Limone"						,35},
	
};
const NUTRITIONAL_VALUES NutritionalTableVegetables[] = 
{
	{"Melanzana"				,24},
	{"Carciofo"					,47},
	{"Avocado"					,160},
	{"Cavolfiore"				,25},
	{"Broccoli"					,35},
	{"Fagioli"					,25},
	{"Crescione"				,19},
	{"Funghi"					,22},
	{"Cavolo cinese"			,13},
	{"Peperoncino"				,40},
	{"Piselli"					,82},
	{"Insalata iceberg"			,14},
	{"Finocchio"				,31},
	{"Cetriolo"					,15},
	{"Cavolo riccio"			,49},
	{"Carota"					,36},
	{"Patata"					,86},
	{"Cavolo rapa"				,27},
	{"Zucca"					,19},
	{"Porro"					,31},
	{"Mais"						,108},
	{"Bietola"					,19},
	{"Peperone"					,21},
	{"Ravanello"				,16},
	{"Barbabietola"				,43},
	{"Cavolo rosso"				,29},
	{"Cavolo Bruxelles"			,43},
	{"Rucola"					,25},
	{"Asparagi"					,18},
	{"Spinaci"					,23},
	{"Patata dolce"				,76},
	{"Zucchina"					,20},
	{"Cipolla"					,40},
	
};
const NUTRITIONAL_VALUES NutritionalTableMeat[] = 
{
	{"Salsiccia"					,375},
	{"Anatra"						,375},
	{"Cervo"						,375},
	{"Petto pollo"					,75},
	{"Carne vitello"				,94},
	{"Agnello"						,178},
	{"Petto tacchino"				,111},
	{"Salame"						,507},
	{"Prosciutto"					,335},
	{"Lardo"						,645},
	{"Filetto manzo"				,115},
	{"Macinato manzo"				,212},
	{"Costata manzo"				,162},
	{"Filetto maiale"				,171},
	{"Maiale, grasso"				,311},
	{"Maiale, magro"				,143},
	{"Cotoletta maiale"				,105},
	{"Würstel"						,375},
	{"Ragu"						    ,150},
	
};
const NUTRITIONAL_VALUES NutritionalTableFish[] = 
{
	{"Trota"						,50},
	// {"Luccio"						,50},
	{"Aringa"						,146},
	{"Salmone"						,137},
	// {"Filetto scorfano"				,111},
	{"Filetto merluzzo"				,83},
	{"Tonno"						,144},
	
};
const NUTRITIONAL_VALUES NutritionalTableCheese[] = 
{
	{"Latticello"				,38},
	{"Creme fraiche"			,292},
	{"Cheddar"					,403},
	{"Emmental"					,382},
	{"Edamer"					,251},
	{"Uovo"						,155},
	{"Fiocchi di latte"			,104},
	{"Latte di cocco"			,136},
	{"Latte"					,47},
	{"Quark magro"				,67},
	{"Yogurt bianco"			,62},
	{"Panna"					,204},
	{"Panna da cucina"			,162},
	{"Panna acida"				,115},
	// {"Smetana"					,240},
	
};
const NUTRITIONAL_VALUES NutritionalTablePasta[] = 
{
	{"Fettuccine"				,142},
	{"Pasta di farro"			,128},
	{"Farfalle"					,147},
	{"Tagliatelle"				,159},
	{"Pasta di riso"			,124},
	{"Spaghetti integ."			,152},
	{"Riso basmati"				,340},
	{"Riso integrale"			,337},	
	
};
const NUTRITIONAL_VALUES NutritionalTableBread[] = 
{
	{"Baguette"				,248},
	{"Brezel"				,217},
	{"Ciabatta"				,333},
	{"Croissant"			,393},
	{"Pane naan"			,290},
	{"Pita"					,290},
	{"Integrale"			,247},
	{"Dolce segale"			,181},
	{"Toast integrale"		,244},	
	{"Wrap integrale"		,170},
	{"Girella cannella"		,384},	
	
};
const NUTRITIONAL_VALUES NutritionalTableJunkFood[] = 
{
	{"Cheeseburger"					,250},
	{"Patatine"						,539},
	{"Currywurst"					,288},
	{"Kebab"						,215},
	{"Bisc. cioccolato"				,512},
	{"Kebab veg."					,107},
	{"Pizza margherita"				,199},
	{"Pizza con salame"				,245},	
	{"Patatine fritte"				,291},
	{"Hamburger"					,291},
	{"Nutella"						,547},
};


const NUTRITIONAL_CATEGORIES CategoryTable[] = 
{
	{"Verdura"  		,NutritionalTableVegetables, (sizeof(NutritionalTableVegetables)/sizeof(NUTRITIONAL_VALUES))},
	{"Frutta" 			,NutritionalTableFruits,     (sizeof(NutritionalTableFruits)/sizeof(NUTRITIONAL_VALUES))},
	{"Carne" 			,NutritionalTableMeat,       (sizeof(NutritionalTableMeat)/sizeof(NUTRITIONAL_VALUES))},
	{"Pesce" 			,NutritionalTableFish, 	     (sizeof(NutritionalTableFish)/sizeof(NUTRITIONAL_VALUES))},
	{"Latticini/uova" 	,NutritionalTableCheese,	 (sizeof(NutritionalTableCheese)/sizeof(NUTRITIONAL_VALUES))},
	{"Pasta" 			,NutritionalTablePasta, 	 (sizeof(NutritionalTablePasta)/sizeof(NUTRITIONAL_VALUES))},
	{"Pane e co." 		,NutritionalTableBread, 	 (sizeof(NutritionalTableBread)/sizeof(NUTRITIONAL_VALUES))},
	{"Cheat meal" 		,NutritionalTableJunkFood,   (sizeof(NutritionalTableJunkFood)/sizeof(NUTRITIONAL_VALUES))},
};
#endif




