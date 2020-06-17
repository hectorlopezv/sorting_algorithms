array = [24, 52 ,52 , 82,6,5,52,35,70,96,91,92,61,96,34,32,42,12,
17,93,85,30,83,63,2,89,43,82,92,59,7,46,86,61,36,56,85,4,65,72,73,
4,33,12,54,23,4,48,8,65]

def selectionsort(array, size):
    
    print(array)
    for i in range(size):
        print("this postion array {}".format(array[i]))
        sele = array[i]
        temp_min = array[i]
        idx_min = 0
        print("valor temp_mayor{}".format(sele))
        
        for j in range(i + 1, size):
            
            if sele > array[j]:
               
                if array[j] < sele:
                    
                    if array[j] < temp_min:
                        temp_min = array[j]
                        idx_min = j
                        print("Valor del temp_min {}".format(temp_min))
                    
                sele = array[j]
            
            
        print("array[i] {}".format(array[i]))
  
        print("array[idx_min] {}".format(array[idx_min]))
        print(idx_min)
        if sele != array[i]:#hay alguno que fuera menor basicamente
            array[i], array[idx_min] = array[idx_min], array[i]    
        print("despues del swap")
        print(array)
    
        print("valor del min{}".format( temp_min))
        

   
selectionsort(array, len(array))

