def binary_search arr, target
  
  min_index =0
  max_index = arr.length - 1
  
  while(min_index <= max_index)
    midpoint = (max_index + min_index)/2
    if arr[midpoint] > target
      max_index = midpoint -1
    elsif arr[midpoint] < target
      min_index = midpoint + 1
    else
      return midpoint
    end
  end
  
  return -1
end
