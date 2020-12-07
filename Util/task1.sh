runTest() {
    for i in {1..12}
    do
        local filename="T0$i.exe"
        if [ $i -gt 9 ]
        then
            filename="T$i.exe"
        fi

        if [ $i -eq 1 ]
        then
            ./src ../Suite_of_12_Tests/$filename > VMOutput.txt
        else
            ./src ../Suite_of_12_Tests/$filename >> VMOutput.txt
        fi
    done

    ./aunit VMOutput.txt

}

runTest
