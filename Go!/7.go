package main

import "fmt"

func main() {
    var arr [10]int
    for i := 0; i < 5; i++ {
        arr[i] = i
    }
    fmt.Printf("%v\n",arr)
}