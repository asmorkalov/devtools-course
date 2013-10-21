# This function executes command and stops 
# exectution if return status wasn't 0
function try {
    "$@"
    status=$?
    if [ $status -ne 0 ]; then
        echo "ERROR with '$@' in $dir"
        exit $status
    fi
    return $status
}

function Header {
    echo ""
    echo "*****************************************************"
    echo "$@"
    echo "*****************************************************"
    echo ""
}

# Go through all directories, check Google style and run 'make test'
for dir in */; 
do
    cd $dir

    Header "Check \"Google C++ Style\" in $dir"

    hpp_files=`find . -name "*.hpp"`
    if [ $hpp_files ]; then
        echo "ERROR: Please use *.h extension instead of *.hpp:"
        echo " - $hpp_files"
        # exit 1
    fi

    sources=`find . -name "*.hpp" -or -name "*.h" -or -name "*.cpp"`
    for file in $sources;
    do
        echo "Analysing $file"
        python ../cpplint.py $file
        # try python ../cpplint.py $file
    done

    Header "Build and Test $dir"
    if [ -f Makefile ];
    then
       echo "Makefile exists"
       try make test
    else
       echo "No Makefile"
    fi

    cd ..
done