#!/bin/bash
cp space.dat backup_space.dat
cp input.dat backup_input.dat
echo "" > space.dat
echo "" > input.dat
mkdir result
g++ -std=c++11 -o a main.cpp

function do_1(){
	case "$2" in
		"undergraduate") filter="Undergraduate";;
		"graduate") filter="Graduate";;
		"faculty") filter="Faculty";;
		"studyroom") filter="StudyRoom";;
		"seat") filter="Seat";;
		"book") filter="Book";;
		"e-book") filter="E-book";;
		"magazine") filter="Magazine";;
	esac
	if [ "$1" \= "resource" ]
	then
		grep $filter backup_input.dat > result/$1/$2.dat
	else
		grep $filter backup_$1.dat > $1.dat
		if [ -s $1.dat ]
		then
			./a
			cp output.dat result/$1/$2.dat
		else
			echo " " > result/$1/$2.dat 
		fi
	fi
	echo "" > input.dat
}

function do_2(){
	case "$1" in
		"studyroom") filter="StudyRoom";;
		"seat") filter="Seat";;
	esac
	cp backup_space.dat save.dat
	sed -i '1d' save.dat
	sed -i '1d' backup_space.dat
	grep $filter backup_space.dat | awk '{print $3}' > temp.dat
	while read line;
	do
		echo $line > lf.dat
		tl=$(cat lf.dat)
		if [ "$tl" \= "$2" -o "$2" \= "all" ]
		then
			sed -n '1p' save.dat >> space.dat
			sed -i '1d' save.dat
		else
			sed -i '1d' save.dat
		fi
	done < temp.dat
	if [ -s space.dat ]
	then
		./a
		cp output.dat result/space/$1.dat
	else
		echo " " > result/space/$1.dat
	fi
	rm lf.dat
	rm temp.dat
	rm save.dat
	echo "" > space.dat
}

if [ "$1" \= "resource" ]
then
	mkdir result/resource
	if [ "$2" \= "all" ]
	then
		do_1 $1 "book"
		do_1 $1 "e-book"
		do_1 $1 "magazine"
	else
		do_1 $1 $2
	fi
elif [ "$1" \= "input" ]
then
	mkdir result/input
	if [ "$2" \= "date" ]
	then
		cp backup_input.dat save.dat
		sed -i '1d' save.dat
		awk '{print $1}' backup_input.dat | sed 's/\///g' > temp.dat
		sed -i '1d' temp.dat
		echo $3 | sed 's/\///g' > st.dat	
		third=$(cat st.dat)
		echo $4 | sed 's/\///g' > st.dat	
		fourth=$(cat st.dat)
		while read line;
		do
			if [ "$line" \> "$third" -o "$line" \= "$third" ]
			then
				if [ "$line" \< "$fourth" -o "$line" \= "$fourth" ]
				then
					sed -n '1p' save.dat >> input.dat
					sed -i '1d' save.dat
				else
					sed -i '1d' save.dat
				fi
			else
				sed -i '1d' save.dat
			fi
		done < temp.dat
		./a
		cp output.dat result/input/date.dat
		rm save.dat
		rm temp.dat
		rm st.dat
	elif [ "$2" \= "all" ]
	then
		do_1 $1 "book"
		do_1 $1 "e-book"
		do_1 $1 "magazine"
		do_1 $1 "undergraduate"
		do_1 $1 "graduate"
		do_1 $1 "faculty"
	else
		do_1 $1 $2
	fi
elif [ "$1" \=  "space" ]
then
	mkdir result/space
	if [ "$2" \= "date" ]
	then
		cp backup_space.dat save.dat
		sed -i '1d' save.dat
		awk '{print $1}' backup_space.dat | sed 's/\///g' > temp.dat
		sed -i '1d' temp.dat
		echo $3 | sed 's/\///g' > st.dat	
		third=$(cat st.dat)
		echo $4 | sed 's/\///g' > st.dat	
		fourth=$(cat st.dat)
		while read line;
		do
			echo $line | sed 's/\([0-9]\{2\}\)//' > st.dat
			li=$(cat st.dat)
			if [ "$li" \> "$third" -o "$li" \= "$third" ]
			then
				if [ "$li" \< "$fourth" -o "$li" \= "$fourth" ]
				then
					sed -n '1p' save.dat >> space.dat
					sed -i '1d' save.dat
				else
					sed -i '1d' save.dat
				fi
			else
				sed -i '1d' save.dat
			fi
		done < temp.dat
		./a
		cp output.dat result/space/date.dat
		rm save.dat
		rm temp.dat
		rm st.dat
	elif [ "$2" \= "all" ]
	then
		do_2 "studyroom" "all"
		do_2 "seat" "all"
		do_1 $1 "undergraduate"
		do_1 $1 "graduate"
		do_1 $1 "faculty"
	elif [ "$2" \= "studyroom" -o "$2" \= "seat" ]
	then
		do_2 $2 $3
	else
		do_1 $1 $2
	fi
elif [ "$1" \= "output" ]
then
	if [ "$2" \= "stat_table" ]
	then
		mkdir result/output
		rm input.dat
		rm space.dat
		cp backup_input.dat input.dat
		cp backup_space.dat space.dat
		./a
		num_e=0
		num_0=0 
		num_1=0 
		num_2=0 
		num_3=0 
		num_4=0 
		num_5=0 
		num_6=0 
		num_7=0 
		num_8=0 
		num_9=0 
		num_10=0 
		num_11=0 
		num_12=0 
		num_13=0 
		num_14=0 
		num_15=0 
		cp output.dat temp.dat
		sed -i '1d' temp.dat
		awk '{print $2}' temp.dat > t.dat
		while read line;
		do
			code=$line
			case "$code" in
				-1) let num_e=$num_e+1;;
				0) let num_0=$num_0+1;;
				1) let num_1=$num_1+1;;
				2) let num_2=$num_2+1;;
				3) let num_3=$num_3+1;;
				4) let num_4=$num_4+1;;
				5) let num_5=$num_5+1;;
				6) let num_6=$num_6+1;;
				7) let num_7=$num_7+1;;
				8) let num_8=$num_8+1;;
				9) let num_9=$num_9+1;;
				10) let num_10=$num_10+1;;
				11) let num_11=$num_11+1;;
				12) let num_12=$num_12+1;;
				13) let num_13=$num_13+1;;
				14) let num_14=$num_14+1;;
				15) let num_15=$num_15+1;;
			esac
		done < t.dat
		echo -e "Return_code\tNumber" > result/output/stat_table.dat
		echo -e "num_e\t$num_e" >> result/output/stat_table.dat
		echo -e "num_0\t$num_0" >> result/output/stat_table.dat
		echo -e "num_1\t$num_1" >> result/output/stat_table.dat
		echo -e "num_2\t$num_2" >> result/output/stat_table.dat
		echo -e "num_3\t$num_3" >> result/output/stat_table.dat
		echo -e "num_4\t$num_4" >> result/output/stat_table.dat
		echo -e "num_5\t$num_5" >> result/output/stat_table.dat
		echo -e "num_6\t$num_6" >> result/output/stat_table.dat
		echo -e "num_7\t$num_7" >> result/output/stat_table.dat
		echo -e "num_8\t$num_8" >> result/output/stat_table.dat
		echo -e "num_9\t$num_9" >> result/output/stat_table.dat
		echo -e "num_10\t$num_10" >> result/output/stat_table.dat
		echo -e "num_11\t$num_11" >> result/output/stat_table.dat
		echo -e "num_12\t$num_12" >> result/output/stat_table.dat
		echo -e "num_13\t$num_13" >> result/output/stat_table.dat
		echo -e "num_14\t$num_14" >> result/output/stat_table.dat
		echo -e "num_15\t$num_15" >> result/output/stat_table.dat
		rm temp.dat
		rm t.dat
	else
		echo "wrong output"
	fi
fi
rm input.dat
rm space.dat
mv backup_space.dat space.dat
mv backup_input.dat input.dat
