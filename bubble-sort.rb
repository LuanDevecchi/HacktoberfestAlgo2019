def bubble_sort(arr)
  count = 0
  while count < arr.length
    for i in 0...arr.length-1
      if arr[i] > arr[i+1]
        arr[i], arr[i+1] = arr[i+1], arr[i]
      end
    end
    count+=1
  end
  print arr
end

arr = [5, 5, 4, 3, 2, 1]
bubble_sort(arr)