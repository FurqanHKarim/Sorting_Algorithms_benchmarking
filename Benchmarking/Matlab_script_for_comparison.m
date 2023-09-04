random_data = readmatrix("results_for_random.csv");
best_cases = readmatrix("results_for_best_cases.csv");
worst_cases = readmatrix("results_for_worst_cases.csv");

%Bubble Sort-Insertion sort-Selection-STD sort-Histogram
%Selected for Random Values;
x_axis = random_data(:,1);
Bubble_sort     = random_data(:,3);
Insertion_sort  = random_data(:,4);
Selection_sort  = random_data(:,5);
STD_sort        = random_data(:,6);
histogram_sort  = random_data(:,7);
plot(x_axis,Bubble_sort,'LineStyle','--','Color','red','Marker','x');
hold on;
plot(x_axis,Insertion_sort,'LineStyle','--','Color','blue','Marker','x');
plot(x_axis,Selection_sort,'LineStyle','--','Color','green','Marker','x');
plot(x_axis,STD_sort,'LineStyle','--','Color','black','Marker','x');
plot(x_axis,histogram_sort,'LineStyle','--','Color','cyan','Marker','x');
hold off;


