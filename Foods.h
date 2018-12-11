#ifndef FOODS_H
#define FOODS_H
#include <Arduino.h>
#include <stdint.h>

typedef struct
{
	const char*     FoodName;
	const uint16_t  Calories;
	const float     Carbs;
	const float     Prot;
	const float     Fats;
	
}NUTRITIONAL_VALUES;

typedef struct
{
	const char *CategoryName;
	const NUTRITIONAL_VALUES *NutritionalTable;
	uint8_t TableSize;
}NUTRITIONAL_CATEGORIES;

typedef enum
{
	Mela = 0,				
	Ananas,			
	Albicocca,		
	Pera,				
	Banana,			
	Mirtilli,			
	Arancia_rossa,	
	More,				
	Mirtilli_rossi,	
	Fragole,			
	Fico,				
	Pompelmo,			
	Melograno,		
	Melone,			
	Lamponi,			
	Zenzero,			
	Kiwi,				
	Ciliegie,			
	Mandarino,		
	Mango,			
	Prugna,			
	Pesca,			
	Anguria,			
	Uva,				
	Limone,			
	
	MAX_FRUITS_CATEGORIES
}FRUITS_ITEMS;

typedef enum
{
	Melanzana = 0,		
	Carciofo,			
	Avocado,			
	Cavolfiore,		
	Broccoli,			
	Fagioli,			
	Crescione,		
	Funghi,			
	Cavolo_cinese,	
	Peperoncino,		
	Piselli,			
	Insalata_iceberg,	
	Finocchio,		
	Cetriolo,			
	Cavolo_riccio,	
	Carota,			
	Patata,			
	Cavolo_rapa,		
	Zucca,			
	Porro,			
	Mais,				
	Bietola,			
	Peperone,			
	Ravanello,		
	Barbabietola,		
	Cavolo_rosso,		
	Cavolo_Bruxelles,	
	Rucola,			
	Asparagi,			
	Spinaci,			
	Patata_dolce,		
	Zucchina,			
	Cipolla,			

	MAX_VEGETABLES_CATEGORIES
}VEGETABLES_ITEMS;

typedef enum
{
	Salsiccia = 0,		
	Anatra,			
	Cervo,			
	Petto_pollo,		
	Carne_vitello,	
	Agnello,			
	Petto_tacchino,	
	Salame,			
	Prosciutto,		
	Lardo,			
	Filetto_manzo,	
	Macinato_manzo,	
	Costata_manzo,	
	Filetto_maiale,	
	Maiale_grasso,	
	Maiale_magro,	
	Cotoletta_maiale,	
	Wurstel,			
	Ragu,				

	MAX_MEAT_CATEGORIES
}MEAT_ITEMS;

typedef enum
{
	Trota = 0,			
	Aringa,			
	Salmone,			
	Filetto_merluzzo,	
	Tonno,			

	MAX_FISH_CATEGORIES
}FISH_ITEMS;

typedef enum
{
	Latticello,		
	Creme_fraiche,	
	Cheddar,			
	Emmental,			
	Edamer,			
	Uovo,				
	Fiocchi_di_latte,	
	Latte_di_cocco,	
	Latte,			
	Quark_magro,		
	Yogurt_bianco,	
	Panna,			
	Panna_da_cucina,	
	Panna_acida,		
	
	MAX_CHEESE_CATEGORIES
}CHEESE_ITEMS;

typedef enum
{
	Fettuccine = 0,		
	Pasta_di_farro,	
	Farfalle,			
	Tagliatelle,		
	Pasta_di_riso,	
	Spaghetti_integ,	
	Riso_basmati,		
	Riso_integrale,	

	MAX_PASTA_CATEGORIES
}PASTA_ITEMS;

typedef enum
{
	Baguette = 0,			
	Brezel,			
	Ciabatta,			
	Croissant,		
	Pane_naan,		
	Pita,					
	Integrale,		
	Dolce_segale,		
    Toast_integrale,	
	Wrap_integrale,	
	Girella_cannella,
	
	MAX_BREAD_CATEGORIES
}BREAD_ITEMS;

typedef enum
{
	Cheeseburger = 0,		
	Patatine,			
	Currywurst,		
	Kebab,			
	Bisc_cioccolato,	
	Kebab_veg,			
	Pizza_margherita,	
	Pizza_con_salame,	
    Patatine_fritte,	
	Hamburger,		
	Nutella,			
	
	MAX_JUNK_CATEGORIES
}JUNK_ITEMS;


typedef enum
{
	Verdura,  	
	Frutta,		
	
	MAX_CATEGORIES
}CATEGORIES_ITEMS;



extern const NUTRITIONAL_CATEGORIES CategoryTable[];


void CalcNutritionalValues(float Weight, uint8_t Category, uint8_t Food, 
							uint16_t *Calories, uint16_t *Carbs, uint16_t *Prot, 
							uint16_t *Fats);
#endif