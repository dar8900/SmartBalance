#include"Foods.h"

uint8_t NutritionalTableSizes[MAX_CATEGORIES];


/*
//////////////////////////////////////////////////////////////////////////////////////

									FRUTTA

//////////////////////////////////////////////////////////////////////////////////////
*/


const NUTRITIONAL_VALUES NutritionalTableFruits[] PROGMEM = 
{
	{"Acerola"                 , 32     ,  7.69      ,   0.4	 , 0.3	 },
	{"Acqua di cocco"          , 19     ,  3.71      ,   0.72    , 0.2	 },
	{"Albicocche"              , 48     ,  11.12     ,  1.4	     , 0.39	 }, 
	{"Albicocche sciropp."     , 83     ,  21.31     ,  0.64     , 0.11	 }, 
	{"Amarena"                 , 50     ,  12.18     ,  1.0	     , 0.3	 },
	{"Ananas"                  , 50     ,  13.12     ,  0.54     , 0.12	 }, 
	{"Ananas sciropp."         , 60     ,  15.56     ,  0.51     , 0.11	 }, 
	{"Anguria"                 , 30     ,  7.55      ,   0.61    , 0.15	 },
	{"Arancia"                 , 47     ,  11.75     ,  0.94     , 0.12	 }, 
	{"Avocado"                 , 160    ,  8.53      ,   2.0	 , 14.66 },
	{"Banana"                  , 89     ,  22.84     ,  1.09     , 0.33	 }, 
	{"Ciliegia"                , 63     ,  16.01     ,  1.06     , 0.2	 },
	{"Clementina"              , 47     ,  12.02     ,  0.85     , 0.15	 }, 
	{"Cocco essiccato"         , 443    ,  40.91     ,  3.35     , 31.69 },
	{"Crateva religiosa "      , 69     ,  17.6      ,   1.5	 , 0.1	 },
	{"Dattero"                 , 282    ,  75.03     ,  2.45     , 0.39	 },
	{"Fichi secchi"            , 249    ,  63.87     ,  3.3	     , 0.93	 }, 
	{"Fico"                    , 74     ,  19.18     ,  0.75     , 0.3	 },
	{"Fico d'India"            , 41     ,  9.57      ,   0.73    , 0.51	 },
	{"Fragola"                 , 32     ,  7.68      ,   0.67    , 0.3	 },
	{"Frutta candita"          , 322    ,  82.74     ,  0.34     , 0.07	 }, 
	{"Giuggiola"               , 79     ,  20.23     ,  1.2	     , 0.2	 },
	{"Giuggiola essiccata"     , 287    ,  73.6      ,   3.7	 , 1.1	 },
	{"Guava (guayaba)"         , 68     ,  14.32     ,  2.55     , 0.95	 }, 
	{"Kaki"                    , 70     ,  18.59     ,  0.58     , 0.19	 },
	{"Kiwi"                    , 61     ,  14.66     ,  1.14     , 0.52	 }, 
	{"Kiwi giallo (gold)"      , 60     ,  14.23     ,  1.23     , 0.56	 }, 
	{"Kumquat"                 , 71     ,  15.9      ,   1.88    , 0.86	 },
	{"Lampone"                 , 52     ,  11.94     ,  1.2	     , 0.65	 }, 
	{"Latte di cocco"          , 230    ,  5.54      ,   2.29    , 23.84 },
	{"Lime"                    , 30     ,  10.54     ,  0.7	     , 0.2	 },
	{"Limone"                  , 29     ,  9.32      ,   1.1	 , 0.3	 },
	{"Litchi"                  , 66     ,  16.53     ,  0.83     , 0.44	 }, 
	{"Macedonia"               , 73     ,  18.91     ,  0.39     , 0.07	 }, 
	{"Macedonia di frutta"     , 86     ,  22.36     ,  0.41     , 0.1	 },
	{"Mandarino"               , 53     ,  13.34     ,  0.81     , 0.31	 }, 
	{"Mango"                   , 60     ,  14.98     ,  0.82     , 0.38	 },
	{"Mangostano sciropp."     , 73     ,  17.91     ,  0.41     , 0.58	 },
	{"Maracuja"                , 97     ,  23.38     ,  2.2	     , 0.7	 },
	{"Mela"                    , 48     ,  12.76     ,  0.27     , 0.13	 },
	{"Mela(con la buccia)"     , 52     ,  13.81     ,  0.26     , 0.17	 },
	{"Mela cotogna"            , 57     ,  15.3      ,   0.4	 , 0.1	 },
	{"Mela cotta"              , 53     ,  13.64     ,  0.26     , 0.36	 },
	{"Mela selvatica"          , 76     ,  19.95     ,  0.4	     , 0.3	 },
	{"Melagrana"               , 83     ,  18.7      ,   1.67    , 1.17	 },
	{"Mele sciroppate"         , 67     ,  16.7      ,   0.18    , 0.49	 },
	{"Melone"                  , 34     ,  8.16      ,   0.84    , 0.19	 },
	{"Mirtillo"                , 57     ,  14.49     ,  0.74     , 0.33	 },
	{"Mirtillo rosso"          , 46     ,  12.2      ,   0.39    , 0.13	 },
	{"Mora"                    , 43     ,  9.61      ,   1.39    , 0.49	 },
	{"Mora del gelso"          , 43     ,  9.8	     ,  1.44     , 0.39	 },
	{"Nespola"                 , 47     ,  12.14     ,  0.43     , 0.2	 },
	{"Noce di cocco"           , 354    ,  15.23     ,  3.33     , 33.49 },
	{"Olive nere"              , 115    ,  6.26      ,   0.84    , 10.68 },
	{"Olive verdi"             , 145    ,  3.84      ,   1.03    , 15.32 },
	{"Papaya"                  , 43     ,  10.82     ,  0.47     , 0.26	 },
	{"Pera"                    , 58     ,  15.46     ,  0.38     , 0.12	 },
	{"Pera-mela"               , 42     ,  10.65     ,  0.5	     , 0.23	 },
	{"Pesca"                   , 39     ,  9.54      ,   0.91    , 0.25	 },
	{"Pescanoce nettarina"     , 44     ,  10.55     ,  1.06     , 0.32	 },
	{"Pesche sciroppate"       , 74     ,  19.94     ,  0.45     , 0.1	 },
	{"Platano"                 , 122    ,  31.89     ,  1.3	     , 0.37	 },
	{"Pompelmo"                , 32     ,  8.08      ,   0.63    , 0.1	 },
	{"Prugna"                  , 46     ,  11.42     ,  0.7	     , 0.28	 },
	{"Prugne secche"           , 240    ,  63.88     ,  2.18     , 0.38	 },
	{"Rabarbaro"               , 21     ,  4.54      ,   0.9	 , 0.2	 },
	{"Ribes nero"              , 63     ,  15.38     ,  1.4	     , 0.41	 },
	{"Ribes rosso"             , 56     ,  13.8      ,   1.4	 , 0.2	 },
	{"Sambuco"                 , 73     ,  18.4      ,   0.66    , 0.5	 },
	{"Tamarindo"               , 239    ,  62.5      ,   2.8	 , 0.6	 },
	{"Uva"                     , 69     ,  18.1      ,   0.72    , 0.16	 },
	{"Uva passa"               , 302    ,  79.52     ,  3.39     , 0.46	 },
	{"Uva spina"               , 44     ,  10.18     ,  0.88     , 0.58	 },
	{"Uvetta di Corinto"       , 283    ,  74.08     ,  4.08     , 0.27	 },
	
};

/*
//////////////////////////////////////////////////////////////////////////////////////

									VERDURE

//////////////////////////////////////////////////////////////////////////////////////
*/

const NUTRITIONAL_VALUES NutritionalTableVegetables[] PROGMEM = 
{
	{"Acetosa"                  , 22     ,   3.2     , 2.0    , 0.7   },
	{"Alga agar"                , 26     ,   6.75    , 0.54   , 0.03  },
	{"Alga nori"                , 35     ,   5.11    , 5.81   , 0.28  },
	{"Asparagi"                 , 20     ,   3.88    , 2.2    , 0.12  },
	{"Asparagi bolliti"         , 22     ,   4.11    , 2.4    , 0.22  },
	{"Asparagi surgelati"       , 24     ,   4.1     , 3.23   , 0.23  },
	{"Barbabietola"             , 43     ,   9.56    , 1.61   , 0.17  },
	{"Barbabietola bollita"     , 44     ,   9.96    , 1.68   , 0.18  },
	{"Spinacio"                 , 23     ,   2.71    , 2.98   , 0.78  },
	{"spinacio"                 , 19     ,   3.4     , 1.8    , 0.3   },
	{"Bietola"                  , 19     ,   3.74    , 1.8    , 0.2   },
	{"Bietole bollite"          , 20     ,   4.13    , 1.88   , 0.08  },
	{"Borragine"                , 21     ,   3.06    , 1.8    , 0.7   },
	{"Borragini bollite"        , 25     ,   3.55    , 2.09   , 0.81  },
	{"Broccoli bolliti"         , 35     ,   7.18    , 2.38   , 0.41  },
	{"Broccoli italiani"        , 34     ,   6.64    , 2.82   , 0.37  },
	{"Broccoli surgelati"       , 26     ,   4.78    , 2.81   , 0.29  },
	{"Broccolo (fiore)"         , 28     ,   5.24    , 2.98   , 0.35  },
	{"Bucce di patate"          , 58     ,   12.44   , 2.57   , 0.1   },
	{"Carciofi surgelati"       , 38     ,   7.76    , 2.63   , 0.43  },
	{"Carciofo"                 , 47     ,   10.51   , 3.27   , 0.15  },
	{"Carciofo bollito"         , 51     ,   11.39   , 2.89   , 0.34  },
	{"Carciofo Gerusalemme"     , 73     ,   17.44   , 2.0    , 0.01  },
	{"Cardi"                    , 17     ,   4.07    , 0.7    , 0.1   },
	{"Cardi bolliti"            , 20     ,   4.74    , 0.76   , 0.11  },
	{"Carote"                   , 41     ,   9.58    , 0.93   , 0.24  },
	{"Carote bollite"           , 35     ,   8.22    , 0.76   , 0.18  },
	{"Carote surgelate"         , 36     ,   7.9     , 0.78   , 0.46  },
	{"Cavolfiore"               , 25     ,   4.97    , 1.92   , 0.28  },
	{"Cavolfiore bollito"       , 23     ,   4.11    , 1.84   , 0.45  },
	{"Cavolini bruxelles"       , 43     ,   8.95    , 3.38   , 0.3   },
	{"Cavolo"                   , 25     ,   5.8     , 1.28   , 0.1   },
	{"Cavolo bollito"           , 23     ,   5.51    , 1.27   , 0.06  },
	{"Cavolo bollito"           , 23     ,   5.51    , 1.27   , 0.06  },
	{"Cavolo cinese bollit"     , 22     ,   3.81    , 1.14   , 0.72  },
	{"Cavolo rapa"              , 27     ,   6.2     , 1.7    , 0.1   },
	{"Cavolo rosso"             , 31     ,   7.37    , 1.43   , 0.16  },
	{"Cavolo verde"             , 50     ,   10.01   , 3.3    , 0.7   },
	{"Cavolo verde bollito"     , 28     ,   5.63    , 1.9    , 0.4   },
	{"Cetrioli sott'aceto"      , 11     ,   2.26    , 0.33   , 0.2   },
	{"Cetriolo"                 , 12     ,   2.16    , 0.59   , 0.16  },
	{"Cetriolo"                 , 15     ,   3.63    , 0.65   , 0.11  },
	{"Chenopodio ambrosioi"     , 32     ,   7.44    , 0.33   , 0.52  },
	{"Cicoria"                  , 23     ,   4.7     , 1.7    , 0.3   },
	{"Cime di rapa"             , 31     ,   6.09    , 2.95   , 0.3   },
	{"Cime di rapa bollite"     , 32     ,   6.28    , 3.04   , 0.31  },
	{"Cipolla"                  , 40     ,   9.34    , 1.1    , 0.1   },
	{"Cipolla d'inverno"        , 34     ,   6.5     , 1.9    , 0.4   },
	{"Cipolla dolce"            , 32     ,   7.55    , 0.8    , 0.08  },
	{"Cipolle bollite"          , 42     ,   9.56    , 1.36   , 0.19  },
	{"Cipolle bollite"          , 44     ,   10.15   , 1.36   , 0.19  },
	{"Cipollotti"               , 32     ,   7.34    , 1.83   , 0.19  },
	{"Crema di pomodoro"        , 82     ,   18.91   , 4.32   , 0.47  },
	{"Crescione dell'orto"      , 32     ,   5.5     , 2.6    , 0.7   },
	{"Crocchette di patate"     , 175    ,   25.97   , 2.03   , 7.77  },
	{"Cuori di palma"           , 115    ,   25.61   , 2.7    , 0.2   },
	{"Fagioli dall'occhio"      , 94     ,   19.73   , 3.17   , 0.38  },
	{"Fagioli dall'occhio"      , 90     ,   18.83   , 2.95   , 0.35  },
	{"Fagiolini"                , 31     ,   6.97    , 1.83   , 0.22  },
	{"Fagiolini bolliti"        , 35     ,   7.88    , 1.89   , 0.28  },
	{"Fagiolini cotti"          , 39     ,   6.41    , 2.31   , 0.5   },
	{"Fagiolini serpenti"       , 47     ,   8.35    , 2.8    , 0.4   },
	{"Fagiolo goa"              , 49     ,   4.31    , 6.95   , 0.87  },
	{"Farfaraccio"              , 14     ,   3.61    , 0.39   , 0.04  },
	{"Farinello"                , 43     ,   7.3     , 4.2    , 0.8   },
	{"Fave bollite"             , 62     ,   10.1    , 4.8    , 0.5   },
	{"Fave bollite"             , 62     ,   10.1    , 4.8    , 0.5   },
	{"Fave fresche"             , 72     ,   11.7    , 5.6    , 0.6   },
	{"Finocchio"                , 31     ,   7.29    , 1.24   , 0.2   },
	{"Fiori di zucca"           , 15     ,   3.28    , 1.03   , 0.07  },
	{"Fiori di zucca bolli"     , 15     ,   3.18    , 1.09   , 0.08  },
	{"Foglie del broccolo"      , 28     ,   5.24    , 2.98   , 0.35  },
	{"Foglie di amaranto"       , 23     ,   4.02    , 2.46   , 0.33  },
	{"Foglie di amaranto b"     , 21     ,   4.11    , 2.11   , 0.18  },
	{"Foglie barbabietola"      , 22     ,   4.33    , 2.2    , 0.13  },
	{"Foglie di rapa"           , 32     ,   7.13    , 1.5    , 0.3   },
	{"Foglie di rapa"           , 20     ,   4.36    , 1.14   , 0.23  },
	{"Foglie di rapa"           , 20     ,   4.36    , 1.14   , 0.23  },
	{"Foglie di senape"         , 26     ,   4.9     , 2.7    , 0.2   },
	{"Foglie di vite"           , 93     ,   17.31   , 5.6    , 2.12  },
	{"Foglie di zucca"          , 21     ,   3.39    , 2.72   , 0.22  },
	{"Funghi essiccati"         , 284    ,   73.01   , 9.25   , 0.73  },
	{"Germogli alfa alfa"       , 23     ,   2.1     , 3.99   , 0.69  },
	{"Germogli di bambù"        , 27     ,   5.2     , 2.6    , 0.3   },
	{"Germogli di fagioli"      , 67     ,   13.05   , 6.15   , 0.7   },
	{"Germogli lenticchie"      , 106    ,   22.14   , 8.96   , 0.55  },
	{"Germogli di soia"         , 122    ,   9.57    , 13.09  , 6.7   },
	{"Gombo"                    , 31     ,   7.03    , 2.0    , 0.1   },
	{"Igname tropicale"         , 118    ,   27.88   , 1.53   , 0.17  },
	{"Indivia"                  , 17     ,   3.35    , 1.25   , 0.2   },
	{"Indivia belga"            , 17     ,   4.0     , 0.9    , 0.1   },
	{"Insalata valeriana"       , 21     ,   3.6     , 2.0    , 0.4   },
	{"Laminaria"                , 43     ,   9.57    , 1.68   , 0.56  },
	{"Lappa"                    , 72     ,   17.34   , 1.53   , 0.15  },
	{"Lattuga"                  , 13     ,   2.23    , 1.35   , 0.22  },
	{"Lattuga asparago"         , 18     ,   3.65    , 0.85   , 0.3   },
	{"Lattuga iceberg"          , 14     ,   2.97    , 0.9    , 0.14  },
	{"Lattuga riccia"           , 15     ,   2.87    , 1.36   , 0.15  },
	{"Lattuga romana"           , 17     ,   3.29    , 1.23   , 0.3   },
	{"Lattuga rossa"            , 16     ,   2.26    , 1.33   , 0.22  },
	{"Mais bianco bollito"      , 97     ,   21.71   , 3.34   , 1.41  },
	{"Mais bianco dolce"        , 86     ,   19.02   , 3.22   , 1.18  },
	{"Mais bianco"              , 72     ,   18.13   , 1.74   , 0.42  },
	{"Mais bollito"             , 96     ,   20.98   , 3.41   , 1.5   },
	{"Mais dolce"               , 86     ,   18.7    , 3.27   , 1.35  },
	{"Mais in scatola"          , 72     ,   18.13   , 1.74   , 0.42  },
	{"Mais sottovuoto"          , 79     ,   19.44   , 2.41   , 0.5   },
	{"Manioca"                  , 160    ,   38.06   , 1.36   , 0.28  },
	{"Maranta"                  , 65     ,   13.39   , 4.24   , 0.2   },
	{"Melanzana"                , 24     ,   5.7     , 1.01   , 0.19  },
	{"Melanzane bollite"        , 33     ,   8.14    , 0.83   , 0.23  },
	{"Melnzane sott'aceto"      , 49     ,   9.77    , 0.9    , 0.7   },
	{"Melone cinese"            , 13     ,   3.0     , 0.4    , 0.2   },
	{"Moringa (bacello)"        , 37     ,   8.53    , 2.1    , 0.2   },
	{"Moringa (foglie)"         , 64     ,   8.28    , 9.4    , 1.4   },
	{"Muschio irlandese"        , 49     ,   12.29   , 1.51   , 0.16  },
	{"Nopal"                    , 16     ,   3.33    , 1.32   , 0.09  },
	{"Passata di pomodoro"      , 38     ,   8.98    , 1.65   , 0.21  },
	{"Pastinaca"                , 75     ,   17.99   , 1.2    , 0.3   },
	{"Patata dolce"             , 86     ,   20.12   , 1.57   , 0.05  },
	{"Patate"                   , 77     ,   17.47   , 2.02   , 0.09  },
	{"Patate al forno"          , 93     ,   21.15   , 2.5    , 0.13  },
	{"Patate al microonde"      , 100    ,   23.28   , 2.1    , 0.1   },
	{"Patate bianche"           , 69     ,   15.71   , 1.68   , 0.1   },
	{"Patate bia. forno"        , 94     ,   21.08   , 2.1    , 0.15  },
	{"Patate bollite"           , 87     ,   20.13   , 1.87   , 0.1   },
	{"Patate congelate"         , 78     ,   17.47   , 2.38   , 0.16  },
	{"Patate dolci forno"       , 90     ,   20.71   , 2.01   , 0.15  },
	{"Patate dolci bollit"      , 76     ,   17.72   , 1.37   , 0.14  },
	{"Patate fritte surg."      , 150    ,   24.81   , 2.24   , 4.66  },
	{"Patate gratinate"         , 132    ,   11.27   , 5.06   , 7.59  },
	{"Patate O'Brien"           , 81     ,   15.47   , 2.35   , 1.28  },
	{"Patate rosse"             , 70     ,   15.9    , 1.89   , 0.14  },
	{"Patate russet"            , 79     ,   18.07   , 2.14   , 0.08  },
	{"Peperoncino ess."         , 281    ,   51.42   , 11.86  , 8.2   },
	{"Peperoncino Banana"       , 27     ,   5.35    , 1.66   , 0.45  },
	{"Peperoncino jalapeno"     , 29     ,   6.5     , 0.91   , 0.37  },
	{"Peperoncino pasilla"      , 345    ,   51.13   , 12.35  , 15.85 },
	{"Peperoncino piccante"     , 324    ,   69.86   , 10.58  , 5.81  },
	{"Peperoncino serrano"      , 32     ,   6.7     , 1.74   , 0.44  },
	{"Peperone giallo"          , 27     ,   6.32    , 1.0    , 0.21  },
	{"Peperone verde"           , 20     ,   4.64    , 0.86   , 0.17  },
	{"Peperoni rossi"           , 31     ,   6.03    , 0.99   , 0.3   },
	{"Peperoni rossi boll."     , 26     ,   6.11    , 0.92   , 0.2   },
	{"Peperoni verdi"           , 26     ,   6.11    , 0.92   , 0.2   },
	{"Peperoni verdi"           , 28     ,   6.7     , 0.92   , 0.2   },
	{"Piselli bolliti"          , 84     ,   15.63   , 5.36   , 0.22  },
	{"Piselli freschi"          , 81     ,   14.45   , 5.42   , 0.4   },
	{"Piselli in scatola"       , 68     ,   11.36   , 4.47   , 0.8   },
	{"Piselli surgelati"        , 77     ,   13.62   , 5.22   , 0.4   },
	{"Pomodori arancioni"       , 16     ,   3.18    , 1.16   , 0.19  },
	{"Pomodori bolliti"         , 18     ,   4.01    , 0.95   , 0.11  },
	{"Pomodori gialli"          , 15     ,   2.98    , 0.98   , 0.26  },
	{"Pomodori secchi"          , 258    ,   55.76   , 14.11  , 2.97  },
	{"Pomodori secchi sott"     , 213    ,   23.33   , 5.06   , 14.08 },
	{"Pomodori verdi"           , 23     ,   5.1     , 1.2    , 0.2   },
	{"Pomodoro"                 , 18     ,   3.89    , 0.88   , 0.2   },
	{"Pomodoro barattolo"       , 32     ,   7.29    , 1.64   , 0.28  },
	{"Porri bolliti"            , 31     ,   7.62    , 0.81   , 0.2   },
	{"Porri bolliti"            , 31     ,   7.62    , 0.81   , 0.2   },
	{"Porro"                    , 61     ,   14.15   , 1.5    , 0.3   },
	{"Prezzemolo"               , 36     ,   6.33    , 2.97   , 0.79  },
	{"Purè di patate"           , 83     ,   17.57   , 1.91   , 0.57  },
	{"Purè di patate"           , 113    ,   16.81   , 1.86   , 4.22  },
	{"Purè di patate inst."     , 97     ,   10.87   , 1.77   , 5.13  },
	{"Radicchio"                , 23     ,   4.48    , 1.43   , 0.25  },
	{"Radici di cicoria"        , 72     ,   17.51   , 1.4    , 0.2   },
	{"Rapa"                     , 28     ,   6.43    , 0.9    , 0.1   },
	{"Rapa bollita"             , 22     ,   5.06    , 0.71   , 0.08  },
	{"Rapa bollita"             , 22     ,   5.06    , 0.71   , 0.08  },
	{"Ravanello"                , 43     ,   3.6     , 3.81   , 2.53  },
	{"Ravanello bianco"         , 14     ,   2.63    , 1.1    , 0.1   },
	{"Rucola"                   , 25     ,   3.65    , 2.58   , 0.66  },
	{"Rutabaga"                 , 36     ,   8.13    , 1.2    , 0.2   },
	{"Sagittaria"               , 99     ,   20.23   , 5.33   , 0.29  },
	{"Sagittaria bollita"       , 78     ,   16.14   , 4.49   , 0.1   },
	{"Salsa di pomodoro"        , 24     ,   5.38    , 1.32   , 0.18  },
	{"Scalogno"                 , 72     ,   16.8    , 2.5    , 0.1   },
	{"Scorzonera"               , 82     ,   18.6    , 3.3    , 0.2   },
	{"Sedano"                   , 16     ,   2.97    , 0.69   , 0.17  },
	{"Sedano bollito"           , 18     ,   4.0     , 0.83   , 0.16  },
	{"Sedano bollito"           , 18     ,   4.0     , 0.83   , 0.16  },
	{"Sedano rapa"              , 42     ,   9.2     , 1.5    , 0.3   },
	{"Sedano rapa bollito"      , 27     ,   5.9     , 0.96   , 0.19  },
	{"Soia fresca"              , 147    ,   11.05   , 12.95  , 6.8   },
	{"Soia fresca bollita"      , 141    ,   11.05   , 12.35  , 6.4   },
	{"Spinaci"                  , 23     ,   3.63    , 2.86   , 0.39  },
	{"Spinaci bolliti"          , 23     ,   3.75    , 2.97   , 0.26  },
	{"Spinaci bolliti"          , 23     ,   3.75    , 2.97   , 0.26  },
	{"Spinaci Nuova Cal."       , 14     ,   2.5     , 1.5    , 0.2   },
	{"Spinaci surgelati"        , 29     ,   4.21    , 3.63   , 0.57  },
	{"Spirulina"                , 26     ,   2.42    , 5.92   , 0.39  },
	{"Spirulina essiccata"      , 290    ,   23.9    , 57.47  , 7.72  },
	{"Succo di pomodoro"        , 17     ,   4.24    , 0.76   , 0.05  },
	{"Tarassaco"                , 45     ,   9.2     , 2.7    , 0.7   },
	{"Tarassaco bollito"        , 33     ,   6.4     , 2.0    , 0.6   },
	{"Taro"                     , 112    ,   26.46   , 1.5    , 0.2   },
	{"Wakame"                   , 45     ,   9.14    , 3.03   , 0.64  },
	{"Wasabi"                   , 109    ,   23.54   , 4.8    , 0.63  },
	{"Zucca"                    , 26     ,   6.5     , 1.0    , 0.1   },
	{"Zucca bollita"            , 20     ,   4.9     , 0.72   , 0.07  },
	{"Zucca dolce"              , 40     ,   8.7     , 2.0    , 0.5   },
	{"Zucca invernale"          , 45     ,   11.69   , 1.0    , 0.1   },
	{"Zucca spaghetti"          , 31     ,   6.91    , 0.64   , 0.57  },
	{"Zucchina centenaria"      , 19     ,   4.51    , 0.82   , 0.13  },
	{"Zucchine"                 , 16     ,   3.35    , 1.21   , 0.18  },
	{"Zucchine bollite"         , 20     ,   4.31    , 0.91   , 0.31  },
};

/*
//////////////////////////////////////////////////////////////////////////////////////

						 CARNI

//////////////////////////////////////////////////////////////////////////////////////
*/

const NUTRITIONAL_VALUES NutritionalTableCow[] PROGMEM = 
{
	{"Bistecca sottofile."     ,  258   ,   0      ,  17.98   ,  20.08  },
	{"Bistecca fiorentina"     ,  232   ,   0      ,  18.9    ,  16.81  },
	{"Braciola di manzo"       ,  198   ,   0      ,  20.71   ,  12.15  },
	{"Carne in scatola"        ,  246   ,   0      ,  20.52   ,  17.57  },
	{"Carne macinata(10%)"     ,  176   ,   0      ,  20      ,  10     },
	{"Carne macinata(20%)"     ,  254   ,   0      ,  17.17   ,  20     },
	{"Carne macinata(25%)"     ,  293   ,   0      ,  15.76   ,  25     },
	{"Carne macinata(30%)"     ,  332   ,   0      ,  14.35   ,  30     },
	{"Carne per brasato"       ,  265   ,   0      ,  16.98   ,  21.31  },
	{"Carne per hamburger"     ,  215   ,   0      ,  18.59   ,  15     },
	{"Cervello di manzo"       ,  143   ,   1.05   ,  10.86   ,  10.3   },
	{"Controfiletto"           ,  132   ,   0      ,  23.03   ,  4.4    },
	{"Costolette"              ,  175   ,   0.29   ,  19.38   ,  10.7   },
	{"Cuore"                   ,  112   ,   0.14   ,  17.72   ,  3.94   },
	{"Fegato"                  ,  135   ,   3.89   ,  20.36   ,  3.63   },
	{"Fianco"                  ,  149   ,   0      ,  21.72   ,  6.29   },
	{"Filetto"                 ,  274   ,   0      ,  18.15   ,  21.83  },
	{"Lingua"                  ,  224   ,   3.68   ,  14.9    ,  16.09  },
	{"Lombata"                 ,  154   ,   0      ,  21.17   ,  7.06   },
	{"Macinato magro"          ,  137   ,   0      ,  21.41   ,  5      },
	{"Medaglioni"              ,  145   ,   0      ,  20.51   ,  6.36   },
	{"Milza"                   ,  105   ,   0      ,  18.3    ,  3      },
	{"Pancreas"                ,  235   ,   0      ,  15.7    ,  18.6   },
	{"Polmone"                 ,  92    ,   0      ,  16.2    ,  2.5    },
	{"Polpette"                ,  204   ,   0      ,  14.63   ,  15.69  },
	{"Punta di petto"          ,  132   ,   0      ,  21.47   ,  5.11   },
	{"Roast beef"              ,  139   ,   0      ,  20.67   ,  6.21   },
	{"Rognone"                 ,  99    ,   0.29   ,  17.4    ,  3.09   },
	{"Spalla"                  ,  129   ,   0      ,  19.63   ,  5.02   },
	{"Spezzatino"              ,  130   ,   0.12   ,  21.64   ,  4.81   },
	{"Timo (animelle)"         ,  236   ,   0      ,  12.18   ,  20.35  },
	{"Trippa"                  ,  85    ,   0      ,  12.07   ,  3.69   },
	
};

const NUTRITIONAL_VALUES NutritionalTablePork[] = 
{
	{"Braciola di maiale"     , 202   ,   0.83  ,    24.73   , 11.13  },
	{"Macinato maiale"        , 263   ,   0     ,    16.88   , 21.19  },
	{"Cervello di maiale"     , 127   ,   0     ,    10.28   , 9.21   },
	{"Coda di maiale"         , 378   ,   0     ,    17.75   , 33.5   },
	{"Costine di maiale"      , 277   ,   0     ,    15.47   , 23.4   },
	{"Costine arrosto"        , 361   ,   0     ,    20.89   , 30.86  },
	{"Costine brasate"        , 397   ,   0     ,    29.06   , 30.3   },
	{"Cuore di maiale"        , 118   ,   1.33  ,    17.27   , 4.36   },
	{"Fegato di maiale"       , 134   ,   2.47  ,    21.39   , 3.65   },
	{"Frattaglie di maiale"   , 182   ,   0     ,    7.64    , 16.61  },
	{"Grasso del maiale"      , 632   ,   0     ,    9.25    , 65.7   },
	{"Guanciale di maiale"    , 655   ,   0     ,    6.38    , 69.61  },
	{"Lardo di maiale"        , 857   ,   0     ,    1.76    , 94.16  },
	{"Lingua di maiale"       , 225   ,   0     ,    16.3    , 17.2   },
	{"Macinato magro"         , 121   ,   0.21  ,    21.1    , 4      },
	{"Milza di maiale"        , 100   ,   0     ,    17.86   , 2.59   },
	{"Pancetta"               , 458   ,   0.66  ,    11.6    , 45.04  },
	{"Pancetta al forno"      , 548   ,   1.35  ,    35.73   , 43.27  },
	{"Pancetta microonde"     , 505   ,   1.05  ,    38.62   , 37.27  },
	{"Pancetta padella"       , 533   ,   1.5   ,    38.34   , 40.3   },
	{"Pancia di maiale"       , 518   ,   0     ,    9.34    , 53.01  },
	{"Pancreas di maiale"     , 199   ,   0     ,    18.56   , 13.24  },
	{"Polmone di maiale"      , 85    ,   0     ,    14.08   , 2.72   },
	{"Rognone(rene)"          , 100   ,   0     ,    16.46   , 3.25   },
	{"Spalla grassa"          , 812   ,   0     ,    2.92    , 88.69  },
	{"Trippa di maiale"       , 159   ,   0     ,    16.85   , 10.14  },
	{"Zampa di maiale"        , 212   ,   0     ,    23.16   , 12.59  },
	{"Zampa salamoia"         , 140   ,   0.01  ,    11.63   , 10.02  },
	{"Zampa in umido"         , 232   ,   0     ,    21.94   , 16.05  },
	
};

const NUTRITIONAL_VALUES NutritionalTableChiken[] PROGMEM = 
{
	{"Ali di pollo arrosto"        , 203    ,   0      ,   30.46   ,   8.13   },
	{"Ali di pollo crude"          , 126    ,   0      ,   21.97   ,   3.54   },
	{"Ali di pollo fritte"         , 211    ,   0      ,   30.15   ,   9.15   },
	{"Ali pollo in umido"          , 181    ,   0      ,   27.18   ,   7.18   },
	{"Ali tacchino arrosto"        , 163    ,   0      ,   30.85   ,   3.44   },
	{"Anatra"                      , 135    ,   0.94   ,   18.28   ,   5.95   },
	{"Anatra arrosto"              , 201    ,   0      ,   23.48   ,   11.2   },
	{"Cosce pollo fritte"          , 195    ,   0      ,   28.62   ,   8.08   },
	{"Cosce pollo in umido"        , 169    ,   0      ,   27.5    ,   5.71   },
	{"Coscia di fagiano"           , 134    ,   0      ,   22.2    ,   4.3    },
	{"Coscia di pollo"             , 115    ,   0      ,   18.84   ,   3.82   },
	{"Cosciotti arrosto"           , 174    ,   0      ,   24.22   ,   7.8    },
	{"Cosciotti crudi"             , 120    ,   0      ,   19.16   ,   4.22   },
	{"Cosciotti fritti"            , 208    ,   0.65   ,   28.38   ,   9.32   },
	{"Cosciotti in umido"          , 185    ,   0      ,   26.26   ,   8.06   },
	{"Cosciotti tacchino"          , 159    ,   0      ,   29.19   ,   3.77   },
	{"Crocchette di pollo"         , 296    ,   14.09  ,   15.27   ,   19.82  },
	{"Cuore di pollo"              , 153    ,   0.71   ,   15.55   ,   9.33   },
	{"Cuore pollo in umido"        , 185    ,   0.1    ,   26.41   ,   7.92   },
	{"Durello di pollo"            , 94     ,   0      ,   17.66   ,   2.06   },
	{"Durello pollo umido"         , 154    ,   0      ,   30.39   ,   2.68   },
	{"Durello di tacchino"         , 118    ,   0      ,   19.14   ,   4.58   },
	{"Durello di tacchino"         , 129    ,   0.38   ,   21.72   ,   3.87   },
	{"Fagiano"                     , 133    ,   0      ,   23.57   ,   3.64   },
	{"Faraona"                     , 110    ,   0      ,   20.64   ,   2.47   },
	{"Fegatini di pollo"           , 119    ,   0.73   ,   16.92   ,   4.83   },
	{"Fegatini pollo fri."         , 172    ,   1.11   ,   25.78   ,   6.43   },
	{"Fegatini pollo umido"        , 167    ,   0.87   ,   24.46   ,   6.51   },
	{"Fegato d'anatra"             , 136    ,   3.53   ,   18.74   ,   4.64   },
	{"Fegato di tacchino"          , 228    ,   2.26   ,   17.84   ,   16.36  },
	{"Fegato d'oca"                , 133    ,   6.32   ,   16.37   ,   4.28   },
	{"Fesa di tacchino"            , 111    ,   0      ,   24.6    ,   0.65   },
	{"Fesa di tacchino"            , 135    ,   0      ,   30.06   ,   0.74   },
	{"Frattaglie di cappon"        , 130    ,   1.42   ,   18.28   ,   5.18   },
	{"Frattaglie di cappon"        , 164    ,   0.76   ,   26.39   ,   5.4    },
	{"Frattaglie di pollo"         , 157    ,   0      ,   27.15   ,   4.5    },
	{"Frattaglie di pollo"         , 124    ,   1.8    ,   17.88   ,   4.47   },
	{"Frattaglie di pollo"         , 277    ,   4.35   ,   32.54   ,   13.46  },
	{"Gallina"                     , 137    ,   0.0    ,   23.1    ,   4.21   },
	{"Gallina in umido"            , 213    ,   0.0    ,   33.04   ,   7.98   },
	{"Oca"                         , 161    ,   0.0    ,   22.75   ,   7.13   },
	{"Oca arrosto"                 , 238    ,   0.0    ,   28.97   ,   12.67  },
	{"Paté de foie gras"           , 462    ,   4.67   ,   11.4    ,   43.84  },
	{"Petto di fagiano"            , 133    ,   0.0    ,   24.37   ,   3.25   },
	{"Petto di pollo"              , 114    ,   0.0    ,   21.23   ,   2.59   },
	{"Petto al microonde"          , 252    ,   17.56  ,   16.35   ,   12.89  },
	{"Petto arrosto"               , 165    ,   0.0    ,   31.02   ,   3.57   },
	{"Petto fritto"                , 187    ,   0.51   ,   33.44   ,   4.71   },
	{"Petto in umido"              , 151    ,   0.0    ,   28.98   ,   3.03   },
	{"Petto di quaglia"            , 123    ,   0.0    ,   22.59   ,   2.99   },
	{"Piccione"                    , 142    ,   0.0    ,   17.5    ,   7.5    },
	{"Polpette di pollo"           , 287    ,   12.84  ,   14.85   ,   19.58  },
	{"Polpette di tacchino"        , 283    ,   15.7   ,   14      ,   18     },
	{"Quaglia"                     , 134    ,   0.0    ,   21.76   ,   4.53   },
	{"Sovracosce arrosto"          , 177    ,   0.0    ,   23.99   ,   8.27   },
	{"Sovracosce crude"            , 119    ,   0.0    ,   19.26   ,   4.11   },
	{"Sovracosce fritte"           , 218    ,   1.18   ,   28.18   ,   10.3   },
	{"Sovracosce in umido"         , 195    ,   0.0    ,   25      ,   9.79   },
	{"Struzzo"                     , 117    ,   0.0    ,   21.81   ,   2.65   },
	{"Tacchino arrosto"            , 170    ,   0.0    ,   29.32   ,   4.97   },
	
};

/*
//////////////////////////////////////////////////////////////////////////////////////

									PESCE

//////////////////////////////////////////////////////////////////////////////////////
*/


const NUTRITIONAL_VALUES NutritionalTableFish[] PROGMEM = 
{
	{"Acciughe"                , 131   ,   0.0     ,   20.35   ,   4.84   },
	{"Acciughe sott'olio"      , 210   ,   0.0     ,   28.89   ,   9.71   },
	{"Alosa"                   , 197   ,   0.0     ,   16.93   ,   13.77  },
	{"Anguilla"                , 184   ,   0.0     ,   18.44   ,   11.66  },
	{"Aragosta"                , 77    ,   0.0     ,   16.52   ,   0.75   },
	{"Aragosta in umido"       , 89    ,   0.0     ,   19.0    ,   0.86   },
	{"Aringa"                  , 158   ,   0.0     ,   17.96   ,   9.04   },
	{"Aringa affumicata"       , 217   ,   0.0     ,   24.58   ,   12.37  },
	{"Aringa del Pacifico"     , 195   ,   0.0     ,   16.39   ,   13.88  },
	{"Aringa marinata"         , 262   ,   9.64    ,   14.19   ,   18.0   },
	{"Bottatrice"              , 90    ,   0.0     ,   19.31   ,   0.81   },
	{"Branziono o spigola"     , 97    ,   0.0     ,   18.43   ,   2.0    },
	{"Brosmio"                 , 87    ,   0.0     ,   18.99   ,   0.69   },
	{"Butterfish"              , 146   ,   0.0     ,   17.28   ,   8.02   },
	{"Calamari"                , 92    ,   3.08    ,   15.58   ,   1.38   },
	{"Calamari fritti"         , 175   ,   7.79    ,   17.94   ,   7.48   },
	{"Capasanta"               , 69    ,   3.18    ,   12.06   ,   0.49   },
	{"Carpa"                   , 127   ,   0.0     ,   17.83   ,   5.6    },
	{"Caviale"                 , 264   ,   4.0     ,   24.6    ,   17.9   },
	{"Cefalo o muggine"        , 117   ,   0.0     ,   19.35   ,   3.79   },
	{"Cernia"                  , 92    ,   0.0     ,   19.38   ,   1.02   },
	{"Cozze"                   , 86    ,   3.69    ,   11.9    ,   2.24   },
	{"Cozze alla marinara"     , 172   ,   7.39    ,   23.8    ,   4.48   },
	{"Gamberetti scatola"      , 100   ,   0.0     ,   20.42   ,   1.36   },
	{"Gamberi"                 , 71    ,   0.91    ,   13.61   ,   1.01   },
	{"Gamberi impanati fr."    , 242   ,   11.47   ,   21.39   ,   12.28  },
	{"Gamberi in umido"        , 119   ,   1.52    ,   22.78   ,   1.7    },
	{"Gambero acqua dolce"     , 77    ,   0.0     ,   15.97   ,   0.95   },
	{"Granchio"                , 84    ,   0.0     ,   18.29   ,   0.6    },
	{"Granchio barattolo"      , 83    ,   0.0     ,   17.88   ,   0.74   },
	{"Granchio in umido"       , 97    ,   0.0     ,   19.35   ,   1.54   },
	{"Halibut"                 , 91    ,   0.0     ,   18.56   ,   1.33   },
	{"Lampuga"                 , 85    ,   0.0     ,   18.5    ,   0.7    },
	{"Lavarello o coregone"    , 134   ,   0.0     ,   19.09   ,   5.86   },
	{"Luccio"                  , 88    ,   0.0     ,   19.26   ,   0.69   },
	{"Lumache di mare"         , 90    ,   2.0     ,   16.1    ,   1.4    },
	{"Medusa sotto sale"       , 36    ,   0.0     ,   5.5     ,   1.4    },
	{"Merluzzo"                , 82    ,   0.0     ,   17.81   ,   0.67   },
	{"Merluzzo nero"           , 92    ,   0.0     ,   19.44   ,   0.98   },
	{"Merluzzo nordico"        , 69    ,   0.0     ,   15.27   ,   0.41   },
	{"Molva"                   , 87    ,   0.0     ,   18.99   ,   0.64   },
	{"Orecchie di mare"        , 105   ,   6.01    ,   17.1    ,   0.76   },
	{"Osmero americano"        , 97    ,   0.0     ,   17.63   ,   2.42   },
	{"Ostriche"                , 59    ,   5.53    ,   5.22    ,   1.55   },
	{"Pesce Asinello"          , 74    ,   0.0     ,   16.32   ,   0.45   },
	{"Pesce Asinello affu."    , 116   ,   0.0     ,   25.23   ,   0.96   },
	{"Pesce gatto"             , 119   ,   0.0     ,   15.23   ,   5.94   },
	{"Pesce latte"             , 148   ,   0.0     ,   20.53   ,   6.73   },
	{"Pesce lupo"              , 96    ,   0.0     ,   17.5    ,   2.39   },
	{"Pesce persico"           , 114   ,   0.0     ,   18.86   ,   3.69   },
	{"Pesce pietra"            , 90    ,   0.0     ,   18.36   ,   1.34   },
	{"Pesce Pollock"           , 56    ,   0.0     ,   12.19   ,   0.41   },
	{"Pesce serra"             , 124   ,   0.0     ,   20.04   ,   4.24   },
	{"Pesce spada"             , 144   ,   0.0     ,   19.66   ,   6.65   },
	{"Polpo"                   , 82    ,   2.2     ,   14.91   ,   1.04   },
	{"Polpo in umido"          , 164   ,   4.4     ,   29.82   ,   2.08   },
	{"Rana pescatrice"         , 76    ,   0.0     ,   14.48   ,   1.52   },
	{"Ricciola"                , 146   ,   0.0     ,   23.14   ,   5.24   },
	{"Rombo"                   , 95    ,   0.0     ,   16.05   ,   2.95   },
	{"Salmone"                 , 142   ,   0.0     ,   19.84   ,   6.34   },
	{"Salmone affumicato"      , 117   ,   0.0     ,   18.28   ,   4.32   },
	{"Salmone argentato"       , 146   ,   0.0     ,   21.62   ,   5.93   },
	{"Salmone in scatola"      , 136   ,   0.0     ,   24.62   ,   4.21   },
	{"Salmone keta"            , 120   ,   0.0     ,   20.14   ,   3.77   },
	{"Salmone reale"           , 179   ,   0.0     ,   19.93   ,   10.43  },
	{"Salmone rosa"            , 127   ,   0.0     ,   20.5    ,   4.4    },
	{"Salmone rosso"           , 142   ,   0.0     ,   21.31   ,   5.61   },
	{"Sardine in salsa"        , 185   ,   0.54    ,   20.86   ,   10.45  },
	{"Sardine sott'olio"       , 208   ,   0.0     ,   24.62   ,   11.45  },
	{"Seppie"                  , 79    ,   0.82    ,   16.24   ,   0.7    },
	{"Sgombro"                 , 205   ,   0.0     ,   18.6    ,   13.89  },
	{"Sgombro sotto sale"      , 305   ,   0.0     ,   18.5    ,   25.1   },
	{"Sogliola e platessa"     , 70    ,   0.0     ,   12.41   ,   1.93   },
	{"Squalo"                  , 130   ,   0.0     ,   20.98   ,   4.51   },
	{"Stoccafisso"             , 290   ,   0.0     ,   62.82   ,   2.37   },
	{"Storione"                , 105   ,   0.0     ,   16.14   ,   4.04   },
	{"Storione affumicato"     , 173   ,   0.0     ,   31.2    ,   4.4    },
	{"Surimi"                  , 99    ,   6.85    ,   15.18   ,   0.9    },
	{"Tartaruga di mare"       , 89    ,   0.0     ,   19.8    ,   0.5    },
	{"Tonnetto striato"        , 103   ,   0.0     ,   22.0    ,   1.01   },
	{"Tonno al naturale"       , 116   ,   0.0     ,   25.51   ,   0.82   },
	{"Tonno bianco nat."       , 128   ,   0.0     ,   23.62   ,   2.97   },
	{"Tonno bianco olio"       , 186   ,   0.0     ,   26.53   ,   8.08   },
	{"Tonno pinna blu"         , 144   ,   0.0     ,   23.33   ,   4.9    },
	{"Tonno pinne gialle"      , 109   ,   0.0     ,   24.4    ,   0.49   },
	{"Tonno sott'olio"         , 198   ,   0.0     ,   29.13   ,   8.21   },
	{"Trota"                   , 148   ,   0.0     ,   20.77   ,   6.61   },
	{"Trota di mare"           , 104   ,   0.0     ,   16.74   ,   3.61   },
	{"Trota iridea"            , 141   ,   0.0     ,   19.94   ,   6.18   },
	{"Uova di pesce"           , 143   ,   1.5     ,   22.32   ,   6.42   },
	{"Vongole"                 , 86    ,   3.57    ,   14.67   ,   0.96   },
	{"Vongole in vasetto"      , 142   ,   5.9     ,   24.25   ,   1.59   },
	{"Zampe di rana"           , 73    ,   0.0     ,   16.4    ,   0.3    },
};


/*
//////////////////////////////////////////////////////////////////////////////////////

									LATTE E LATTICINI

//////////////////////////////////////////////////////////////////////////////////////
*/


const NUTRITIONAL_VALUES NutritionalTableCheese[] PROGMEM = 
{
	{"Brie"                 ,  334   ,  0.45   ,   20.75  ,  27.68  },
	{"Camembert"            ,  300   ,  0.46   ,   19.8   ,  24.26  },
	{"Caprino"              ,  364   ,  2.54   ,   21.58  ,  29.84  },
	{"Caprino morbido"      ,  268   ,  0.89   ,   18.52  ,  21.08  },
	{"Caprino stagionato"   ,  452   ,  2.17   ,   30.52  ,  35.59  },
	{"Cheddar"              ,  403   ,  1.28   ,   24.9   ,  33.14  },
	{"Cheshire"             ,  387   ,  4.78   ,   23.37  ,  30.6   },
	{"Edam o edammer"       ,  357   ,  1.43   ,   24.99  ,  27.8   },
	{"Emmental"             ,  380   ,  5.38   ,   26.93  ,  27.8   },
	{"Feta"                 ,  264   ,  4.09   ,   14.21  ,  21.28  },
	{"Fiocchi di latte"     ,  86    ,  3.66   ,   11.83  ,  2.45   },
	{"Fiocchi di latte"     ,  95    ,  3.0    ,   10.9   ,  4.2    },
	{"Fonduta"              ,  229   ,  3.77   ,   14.23  ,  13.47  },
	{"Fontina"              ,  389   ,  1.55   ,   25.6   ,  31.14  },
	{"Gorgonzola"           ,  353   ,  2.34   ,   21.4   ,  28.74  },
	{"Grana"                ,  392   ,  3.22   ,   35.75  ,  25.83  },
	{"Gruviera"             ,  413   ,  0.36   ,   29.81  ,  32.34  },
	{"Limburger"            ,  327   ,  0.49   ,   20.05  ,  27.25  },
	{"Latte condensato"     ,  321   ,  54.4   ,   7.91   ,  8.7    },
	{"Latte di bufala"      ,  97    ,  5.18   ,   3.75   ,  6.89   },
	{"Latte di capra"       ,  69    ,  4.45   ,   3.56   ,  4.14   },
	{"Latte di pecora"      ,  108   ,  5.36   ,   5.98   ,  7      },
	{"Latte in polvere"     ,  496   ,  38.42  ,   26.32  ,  26.71  },
	{"Latte intero"         ,  61    ,  4.78   ,   3.15   ,  3.27   },
	{"Latte intero H.Q."    ,  64    ,  4.65   ,   3.28   ,  3.66   },
	{"Latte parz. screm."   ,  50    ,  4.8    ,   3.3    ,  1.98   },
	{"Latte scremato"       ,  34    ,  4.96   ,   3.37   ,  0.08   },
	{"Latte scremato"       ,  42    ,  4.99   ,   3.37   ,  0.97   },
	{"Latte scremato"       ,  362   ,  51.98  ,   36.16  ,  0.77   },
	{"Latte umano"          ,  70    ,  6.89   ,   1.03   ,  4.38   },
	{"Latticello"           ,  62    ,  4.88   ,   3.21   ,  3.31   },
	{"Monterey"             ,  373   ,  0.68   ,   24.48  ,  30.28  },
	{"Mozzarella"           ,  300   ,  2.19   ,   22.17  ,  22.35  },
	{"Mozzarella light"     ,  254   ,  2.77   ,   24.26  ,  15.92  },
	{"Neufchatel"           ,  253   ,  3.59   ,   9.15   ,  22.78  },
	{"Pecorino"             ,  387   ,  3.63   ,   31.8   ,  26.94  },
	{"Port salut"           ,  352   ,  0.57   ,   23.78  ,  28.2   },
	{"Provolone"            ,  351   ,  2.14   ,   25.58  ,  26.62  },
	{"Ricotta"              ,  174   ,  3.04   ,   11.26  ,  12.98  },
	{"Ricotta light"        ,  138   ,  5.14   ,   11.39  ,  7.91   },
	{"Roquefort"            ,  369   ,  2.0    ,   21.54  ,  30.64  },
	{"Siero del latte"      ,  27    ,  5.14   ,   0.85   ,  0.36   },
	{"Sottilette"           ,  334   ,  2.1    ,   24.73  ,  25.01  },
	{"Sottilette light"     ,  215   ,  16.2   ,   16.3   ,  9.5    },
	{"Tilsit"               ,  340   ,  1.88   ,   24.41  ,  25.98  },	
};

/*
//////////////////////////////////////////////////////////////////////////////////////

									UOVA

//////////////////////////////////////////////////////////////////////////////////////
*/



const NUTRITIONAL_VALUES NutritionalTableEggs[] PROGMEM = 
{
{"Albume"            ,  52   ,   0.73  ,   10.9   ,  0.17   },
{"Omelette"          ,  154  ,   0.64  ,   10.57  ,  11.66  },
{"Tuorlo"            ,  322  ,   3.59  ,   15.86  ,  26.54  },
{"Uova strapazzate"  ,  149  ,   1.61  ,   9.99   ,  10.98  },
{"Uovo"              ,  143  ,   0.72  ,   12.56  ,  9.51   },
{"Uovo d'anatra"     ,  185  ,   1.45  ,   12.81  ,  13.77  },
{"Uovo di quaglia"   ,  158  ,   0.41  ,   13.05  ,  11.09  },
{"Uovo di tacchino"  ,  171  ,   1.15  ,   13.68  ,  11.88  },
{"Uovo d'oca"        ,  185  ,   1.35  ,   13.87  ,  13.27  },
{"Uovo fritto"       ,  196  ,   0.83  ,   13.61  ,  14.84  },
{"Uovo in camicia"   ,  143  ,   0.71  ,   12.51  ,  9.47   },
{"Uovo sodo"         ,  155  ,   1.12  ,   12.58  ,  10.61  },
};


/*
//////////////////////////////////////////////////////////////////////////////////////

									PASTA

//////////////////////////////////////////////////////////////////////////////////////
*/



const NUTRITIONAL_VALUES NutritionalTablePasta[] PROGMEM = 
{
	{"Pasta"                 , 371  , 74.67   , 13.04	,  1.51  },
	{"Pasta farina mais"     , 357  , 79.26   , 7.46	,  2.08  },
	{"Pasta fresca uovo"     , 288  , 54.73   , 11.31	,  2.3   },
	{"Pasta integrale"       , 348  , 75.03   , 14.63	,  1.4   },
	{"Spaghetti"             , 371  , 74.67   , 13.04	,  1.51  },
	{"Spaghetti all'uovo"    , 384  , 71.27   , 14.16	,  4.44  },
	{"Spaghetti cinesi"      , 527  , 57.54   , 8.38	,  30.76 },
	{"Spagh. giapp. soba"    , 336  , 74.62   , 14.38	,  0.71  },
	{"Spagh. giapp. somen"   , 356  , 74.1    , 11.35	,  0.81  },
	{"Spaghetti integrali"   , 348  , 75.03   , 14.63	,  1.4   },
	{"Spaghetto di riso"     , 364  , 83.24   , 3.44	,  0.56  },
};

/*
//////////////////////////////////////////////////////////////////////////////////////

									PRODOTTI DA FORNO

//////////////////////////////////////////////////////////////////////////////////////
*/


const NUTRITIONAL_VALUES NutritionalTableBread[] PROGMEM = 
{
	{"Bagel"                 , 250  ,  48.89	,  10.2	     ,    1.53    },
	{"Baguette"              , 412  ,  68.4	    ,  12.0		 ,    9.5     },
	{"Bignè alla crema"      , 334  ,  37.43	,  4.41	     ,    18.52   },
	{"Biscotti"              , 353  ,  44.6	    ,  7.0		 ,    16.3    },
	{"Biscotti al burro"     , 488  ,  58.2	    ,  5.7		 ,    28.4    },
	{"Biscotti cacao crema"  , 469  ,  70.67	,  5.61	     ,    19.78   },
	{"Biscotti al cocco"     , 404  ,  72.2	    ,  3.6		 ,    12.7    },
	{"Biscotti melassa"      , 430  ,  73.8	    ,  5.6		 ,    12.8    },
	{"Biscotti vaniglia"     , 478  ,  67.9	    ,  5.1		 ,    21.1    },
	{"Biscotti zenzero"      , 416  ,  76.9	    ,  5.6		 ,    9.8     },
	{"Biscotti con uvetta"   , 401  ,  68		,  4.1		 ,    13.6    },
	{"Biscotti d'avena"      , 450  ,  68.7	    ,  6.2		 ,    18.1    },
	{"Biscotti fortuna"      , 378  ,  84		,  4.2		 ,    2.7     },
	{"Biscotti di pasta fr"  , 502  ,  64.5	    ,  6.1		 ,    24.1    },
	{"Biscotti gocciole"     , 481  ,  66.8	    ,  5.4		 ,    22.6    },
	{"Biscotti graham crac"  , 423  ,  76.8	    ,  6.9		 ,    10.1    },
	{"Biscotti marshmallow"  , 421  ,  67.7	    ,  4.0		 ,    16.9    },
	{"Biscotti savoiardi"    , 365  ,  59.7	    ,  10.6	     ,    9.1     },
	{"Biscotti strud. fico"  , 348  ,  70.9	    ,  3.7		 ,    7.3     },
	{"Biscotti wafers"       , 433  ,  72.4	    ,  6.6		 ,    14.2    },
	{"Bisgnè non farcito"    , 362  ,  22.8	    ,  9.0		 ,    25.9    },
	{"Brownies"              , 466  ,  50.2	    ,  6.2		 ,    29.1    },
	{"Cheesecake"            , 321  ,  25.5	    ,  5.5		 ,    22.5    },
	{"Ciambelle cioccolo"    , 417  ,  57.4	    ,  4.5		 ,    19.9    },
	{"Cracker al latte"      , 455  ,  69.7	    ,  7.6		 ,    15.8    },
	{"Cracker light"         , 393  ,  82.3	    ,  10.5	     ,    1.6     },
	{"Crackers"              , 421  ,  74.34	,  9.5		 ,    8.85    },
	{"Crackers integrali"    , 398  ,  68.25	,  7.14	     ,    10.71   },
	{"Crackers non salati"   , 434  ,  71.5	    ,  9.2		 ,    11.8    },
	{"Croissant"             , 406  ,  45.8	    ,  8.2		 ,    21      },
	{"Croissant formaggo"    , 414  ,  47.0		,  9.2		 ,    20.9    },
	{"Croissant alla mela"   , 254  ,  37.1	    ,  7.4		 ,    8.7     },
	{"Crostata al cioccola"  , 484  ,  64.48	,  6.08	     ,    22.42   },
	{"Crostini di pane"      , 465  ,  63.5	    ,  10.8	     ,    18.3    },
	{"Cupcake cioccolato"    , 305  ,  67.2	    ,  4.3		 ,    3.7     },
	{"Dolce danese"          , 371  ,  47.8	    ,  5.4		 ,    18.5    },
	{"Dolce danese limone"   , 371  ,  47.8	    ,  5.4		 ,    18.5    },
	{"Doughnuts"             , 452  ,  51.33	,  4.93	     ,    25.25   },
	{"Eclairs"               , 262  ,  24.2	    ,  6.4		 ,    15.7    },
	{"English muffins"       , 223  ,  44.8	    ,  8.7		 ,    2       },
	{"Focaccia"              , 249  ,  35.82	,  8.77	     ,    7.89    },
	{"Lievito secco attivo"  , 325  ,  41.22	,  40.44	 ,    7.61    },
	{"Mince pie"             , 289  ,  48.0		,  2.6		 ,    10.8    },
	{"Muffins al mirtillo"   , 393  ,  49.54	,  5.28	     ,    19.24   },
	{"Pan di spagna"         , 297  ,  57.7	    ,  7.3		 ,    4.3     },
	{"Pancake"               , 225  ,  39.29	,  5.33	     ,    5.17    },
	{"Pancake al burro"      , 227  ,  28.7	    ,  6.8		 ,    9.3     },
	{"Pancake al mirtillo"   , 222  ,  29.0		,  6.1		 ,    9.2     },
	{"Pancake casereccio"    , 227  ,  28.3	    ,  6.4		 ,    9.7     },
	{"Pane"                  , 271  ,  50.0	    ,  8.8		 ,    3.5     },
	{"Pane germe di grano"   , 261  ,  48.3	    ,  9.6		 ,    2.9     },
	{"Pane all'uovo"         , 283  ,  47.8	    ,  9.5		 ,    6       },
	{"Pane arabo"            , 275  ,  55.7	    ,  9.1		 ,    1.2     },
	{"Pane bianco"           , 238  ,  43.91	,  10.66	 ,    2.15    },
	{"Pane d'avena"          , 236  ,  39.8	    ,  10.4	     ,    4.4     },
	{"Pane di crusca"        , 248  ,  47.8	    ,  8.8		 ,    3.4     },
	{"Pane crusca riso"      , 243  ,  43.5	    ,  8.9		 ,    4.6     },
	{"Pane di patate"        , 266  ,  47.07	,  12.5	     ,    3.13    },
	{"Pane di segale"        , 258  ,  48.3	    ,  8.5		 ,    3.3     },
	{"Pane grattugiato"      , 383  ,  68.49	,  14.13	 ,    5.48    },
	{"Pane integrale"        , 247  ,  41.29	,  12.95	 ,    3.35    },
	{"Pane toscano"          , 293  ,  54.4	    ,  9.0		 ,    4       },
	{"Panino per hamburger"  , 278  ,  50.15	,  9.87	     ,    3.76    },
	{"Pasta di guava"        , 379  ,  47.76	,  5.48	     ,    18.5    },
	{"Pasticcini crema/cio"  , 399  ,  60.31	,  3.63	     ,    15.93   },
	{"Pumpernickel"          , 250  ,  47.5	    ,  8.7		 ,    3.1     },
	{"Shortcake"             , 346  ,  48.5	    ,  6.1		 ,    14.2    },
	{"Strudel"               , 274  ,  41.1	    ,  3.3		 ,    11.2    },
	{"Taco"                  , 467  ,  62.72	,  7.08	     ,    20.83   },
	{"Torta al burro"        , 388  ,  48.8	    ,  5.5		 ,    19.9    },
	{"Torta al cioccolato"   , 389  ,  52.84	,  3.48	     ,    20.05   },
	{"Torta al cocco"        , 356  ,  63.2	    ,  4.4		 ,    10.3    },
	{"Torta al limone"       , 285  ,  39.1	    ,  3.8		 ,    12.9    },
	{"Torta alla crema"      , 252  ,  42.9	    ,  2.4		 ,    8.5     },
	{"Torta crema ciocc."    , 304  ,  33.6	    ,  2.6		 ,    19.4    },
	{"Torta noci pecan"      , 412  ,  52.2	    ,  4.9		 ,    22.2    },
	{"Torta alle pesche"     , 223  ,  32.9	    ,  1.9		 ,    10      },
	{"Torta allo zenzero"    , 356  ,  49.2	    ,  3.9		 ,    16.4    },
	{"Torta di banane"       , 269  ,  32.9	    ,  4.4		 ,    13.6    },
	{"Torta di cliegie"      , 270  ,  38.5	    ,  2.8		 ,    12.2    },
	{"Torta di frutta"       , 324  ,  61.6	    ,  2.9		 ,    9.1     },
	{"Torta di mele"         , 265  ,  37.1	    ,  2.4		 ,    12.5    },
	{"Torta di mirtilli"     , 245  ,  33.5	    ,  2.7		 ,    11.9    },
	{"Torta di zucca"        , 204  ,  26.4	    ,  4.5		 ,    9.3     },
	{"Torta fritta limone"   , 316  ,  42.6	    ,  3.0		 ,    16.1    },
	{"Torta fritta cherry"   , 316  ,  42.6	    ,  3.0		 ,    16.1    },
	{"Torta fritta frutta"   , 316  ,  42.6	    ,  3.0		 ,    16.1    },
	{"Torta paradiso"        , 258  ,  57.8	    ,  5.9		 ,    0.8     },
	{"Tortillas"             , 218  ,  44.64	,  5.7		 ,    2.85    },
	{"Waffle"                , 291  ,  32.9	    ,  7.9		 ,    14.1    },
	
};

/*
//////////////////////////////////////////////////////////////////////////////////////

									ALCOLICI

//////////////////////////////////////////////////////////////////////////////////////
*/

const NUTRITIONAL_VALUES NutritionalTableAlcol[] PROGMEM = 
{
	{"Birra"            ,  43  ,  3.55	  ,   0.46   , 0.0	 },
	{"Birra Bud light"  ,  31  ,  1.86	  ,   0.25   , 0.0	 },
	{"Birra Budweiser"  ,  41  ,  2.97	  ,   0.36   , 0.0	 },
	{"Birra Budweiser"  ,  28  ,  0.87	  ,   0.2    , 0.0	 },
	{"Birra light"      ,  29  ,  1.64	  ,   0.24   , 0.0	 },
	{"Daiquiri"         , 186  ,  6.94	  ,   0.06   , 0.06  },
	{"Eggnog"           ,  88  ,  8.05	  ,   4.55   , 4.19  },
	{"Gin"              , 263  ,  0.0	  ,   0.0	 , 0.0   },
	{"Liquore al caffè" , 308  ,  32.2	  ,   0.1	 , 0.3	 },
	{"Pina colada"      , 174  ,  22.66	  ,   0.42   , 1.88  },
	{"Rum"              , 231  ,  0.0	  ,   0.0	 , 0.0	 },
	{"Sake"             , 134  ,  5.0	  ,   0.5	 , 0.0	 },
	{"Spumante dolce"   , 160  ,  13.69	  ,   0.2	 , 0.0	 },
	{"Spumante secco"   , 152  ,  11.67	  ,   0.2	 , 0.0	 },
	{"Tequila sunrise"  , 110  ,  11.3	  ,   0.3    , 0.1	 },
	{"Vodka"            , 231  ,  0.0	  ,   0.0	 , 0.0	 },
	{"Whiskey sour"     , 119  ,  13.4	  ,   0.0	 , 0.0	 },
	{"Whisky"           , 250  ,  0.1	  ,   0.0	 , 0.0   },
};


const NUTRITIONAL_CATEGORIES CategoryTable[] = 
{
	{"Verdura"  		,NutritionalTableVegetables,     &NutritionalTableSizes[0]},
	{"Frutta" 			,NutritionalTableFruits    ,     &NutritionalTableSizes[1]},
	{"Pesce" 			,NutritionalTableFish      , 	 &NutritionalTableSizes[2]},
	{"Latticini" 	    ,NutritionalTableCheese    ,	 &NutritionalTableSizes[3]},
	{"Pasta" 			,NutritionalTablePasta     , 	 &NutritionalTableSizes[4]},
	{"Pane e co." 		,NutritionalTableBread     , 	 &NutritionalTableSizes[5]},
	{"Manzo"     		,NutritionalTableCow       ,     &NutritionalTableSizes[6]},
	{"Maiale" 			,NutritionalTablePork      ,     &NutritionalTableSizes[7]},
	{"Pollame" 	   		,NutritionalTableChiken    ,     &NutritionalTableSizes[8]},
	{"Uova" 		 	,NutritionalTableEggs      ,     &NutritionalTableSizes[9]},
	{"Alcolici" 		,NutritionalTableAlcol     ,     &NutritionalTableSizes[10]},
};


void FillNutritionalTableSizeArray()
{
	uint8_t TableIndx = 0;
	for(TableIndx = 0; TableIndx < MAX_CATEGORIES; TableIndx++)
	{		
		NutritionalTableSizes[TableIndx] = (sizeof(CategoryTable[TableIndx].NutritionalTable)/sizeof(NUTRITIONAL_VALUES));
	}	
}


static uint16_t CalcCalories(float Weight, uint8_t Category, uint8_t Food)
{
	uint16_t CaloriesCalculated = 0, Calories100g = CategoryTable[Category].NutritionalTable[Food].Calories;
	CaloriesCalculated = (uint16_t)((Weight * (float)Calories100g) / 0.100);
	return CaloriesCalculated;
}

static uint16_t CalcCarbs(float Weight, uint8_t Category, uint8_t Food)
{
	uint16_t CarbsCalculated = 0;
	float Carbs100g = CategoryTable[Category].NutritionalTable[Food].Carbs;
	CarbsCalculated = (uint16_t)((Weight * Carbs100g) / 0.100);
	return CarbsCalculated;
}
static uint16_t CalcProt(float Weight, uint8_t Category, uint8_t Food)
{
	uint16_t ProtCalculated = 0;
	float Prot100g = CategoryTable[Category].NutritionalTable[Food].Prot;
	ProtCalculated = (uint16_t)((Weight * Prot100g) / 0.100);
	return ProtCalculated;
}
static uint16_t CalcFats(float Weight, uint8_t Category, uint8_t Food)
{
	uint16_t FatsCalculated = 0;
	float Fats100g = CategoryTable[Category].NutritionalTable[Food].Fats;
	FatsCalculated = (uint16_t)((Weight * Fats100g) / 0.100);
	return FatsCalculated;
}

void CalcNutritionalValues(float Weight, uint8_t Category, uint8_t Food, 
							uint16_t *Calories, uint16_t *Carbs, uint16_t *Prot, 
							uint16_t *Fats)
{
	*Calories = CalcCalories(Weight, Category, Food);
	*Carbs = CalcCarbs(Weight, Category, Food);
	*Prot = CalcProt(Weight, Category, Food);
	*Fats = CalcFats(Weight, Category, Food);
}

