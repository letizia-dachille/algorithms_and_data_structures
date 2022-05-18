cat ../../paris/original/network_temporal_day.csv | awk '{if(NR < 2) print $0 > "../../paris/ordered/network_temporal_day_sorted.csv"; else print $0}' | sort --field-separator=';' -n -k1 -k2 -k5 -k3 >> ../../paris/ordered/network_temporal_day_sorted.csv

#Prototipo:
#cat <file> | awk '{if(NR < 2) print $0 > "<ordered_file>"; else print $0}' | sort --field-separator=';' -n -k1 -k2 -k7 >> <ordered_file>
#Dove <file> è il file da ordinare (path relativo rispetto alla posizione dello script), 
#mentre <ordered_file> è il file ordinato da dare in output.

#Funzionamento:
#cat apre il file e, dopo aver isolato la prima riga ed averla copiata nel file ordinato, ordina tutte le altre e le inserisce in coda nel
#medesimo file (-k* indica la colonna per cui viene ordinato il file).