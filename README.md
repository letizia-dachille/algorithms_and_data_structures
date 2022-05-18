# Algorithms and Data Structures
<p> Rewriting of end-of-course projects in Algorithms and Data Structures by Francesco Caporali and Letizia D'Achille. The work consists of merging and improving two separate projects presented individually. We tried to maximize efficiency in time and memory. The work is written completely in Italian. <p>

Title of the project: <em>City route planner</em> 
  
# Description
The source code in C++ can be found in [code/c++](https://github.com/letizia-dachille/algorithms_and_data_structures/blob/main/code/c++). The data is located in the [paris](https://github.com/letizia-dachille/algorithms_and_data_structures/blob/main/paris) folder, it has been manipulated through some scripts in bash to result in a partial sorting. The <em>network_temporal_day.csv</em> file was omitted because of the excessive memory space taken up (about 90mb). The file can be found [here](https://zenodo.org/record/1186215#.YoUCjpNByfU) (paris.zip file) and should be placed in [paris/original](https://github.com/letizia-dachille/algorithms_and_data_structures/blob/main/paris/original), then reordered via the [order_temporal_day.sh](https://github.com/letizia-dachille/algorithms_and_data_structures/blob/main/code/bash/order_temporal_day.sh) file.
It is sufficient to compile [main.cpp](https://github.com/letizia-dachille/algorithms_and_data_structures/blob/main/code/c++/main.cpp), then run the compiled file.

All files are accompanied by brief comments (written in italian). <br>

# Example
An example of operation is presented below. Selecting <em>Charles de Gaulle Etoile</em> (27457) as the departure stop and <em>Quatre Routes</em> (10122) as the arrival stop, wanting to leave at 11:05 a.m. and wanting to take less than an hour to reach the destination, the following result is obtained.  

![example](https://github.com/letizia-dachille/algorithms_and_data_structures/blob/main/sample_output.png)
  
# License
The content of this project itself is licensed under the [Creative Commons Attribution 4.0 International](https://creativecommons.org/licenses/by/4.0/), and the underlying source code used to format and display that content is licensed under the [GNU General Public License v3.0](https://github.com/letizia-dachille/algorithms_and_data_structures/blob/main/LICENSE).
