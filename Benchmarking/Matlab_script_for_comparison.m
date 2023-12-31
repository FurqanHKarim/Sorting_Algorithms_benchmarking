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


figure;
set(gcf,'Name','Random');
title('Random Data','FontSize',20);
%title('Random values');
plot(x_axis,Bubble_sort,'LineStyle','--','Color','red','Marker','x');
hold on;
plot(x_axis,Insertion_sort,'LineStyle','--','Color','blue','Marker','x');
plot(x_axis,Selection_sort,'LineStyle','--','Color','green','Marker','x');
plot(x_axis,STD_sort,'LineStyle','--','Color','black','Marker','x');
plot(x_axis,histogram_sort,'LineStyle','--','Color','cyan','Marker','x');
legend('Bubble Sort','Insertion Sort','Selection Sort','STD Sort','Histogram Sort');
hold off;


%Selected for Random Values;
x_axis = best_cases(:,1);
Bubble_sort     = best_cases(:,3);
Insertion_sort  = best_cases(:,4);
Selection_sort  = best_cases(:,5);
STD_sort        = best_cases(:,6);
histogram_sort  = best_cases(:,7);


figure;
set(gcf,'Name','Best Case');
title('Best Case');
plot(x_axis,Bubble_sort,'LineStyle','--','Color','red','Marker','x');
hold on;
plot(x_axis,Insertion_sort,'LineStyle','--','Color','blue','Marker','x');
plot(x_axis,Selection_sort,'LineStyle','--','Color','green','Marker','x');
plot(x_axis,STD_sort,'LineStyle','--','Color','black','Marker','x');
plot(x_axis,histogram_sort,'LineStyle','--','Color','cyan','Marker','x');
legend('Bubble Sort','Insertion Sort','Selection Sort','STD Sort','Histogram Sort');
hold off;


%Selected for Random Values;
x_axis = worst_cases(:,1);
Bubble_sort     = worst_cases(:,3);
Insertion_sort  = worst_cases(:,4);
Selection_sort  = worst_cases(:,5);
STD_sort        = worst_cases(:,6);
histogram_sort  = worst_cases(:,7);


figure;
set(gcf,'Name','Worst Case');
title('Worst Case');
plot(x_axis,Bubble_sort,'LineStyle','--','Color','red','Marker','x');
hold on;
plot(x_axis,Insertion_sort,'LineStyle','--','Color','blue','Marker','x');
plot(x_axis,Selection_sort,'LineStyle','--','Color','green','Marker','x');
plot(x_axis,STD_sort,'LineStyle','--','Color','black','Marker','x');
plot(x_axis,histogram_sort,'LineStyle','--','Color','cyan','Marker','x');
legend('Bubble Sort','Insertion Sort','Selection Sort','STD Sort','Histogram Sort');
hold off;

pause;
close all;
clear;