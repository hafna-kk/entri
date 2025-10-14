#include<stdio.h>

typedef struct{
    int vehicle_no;
    char vehicle_name[50];
    int vehicle_wheel_no;

}vehicle;

int main(){
    vehicle tvs ={4565,"TVS",2};
    vehicle toyota= {2345,"itios",4};
    
    printf("vehicle_no:%d ,\n vehicle_name:%s,\n vehicle_wheel_no:%d",tvs.vehicle_no,tvs.vehicle_name,tvs.vehicle_wheel_no);
    printf("\nvehicle_no:%d ,\n vehicle_name:%s,\n vehicle_wheel_no:%d",toyota.vehicle_no,toyota.vehicle_name,toyota.vehicle_wheel_no);
    
    return 0;


}
