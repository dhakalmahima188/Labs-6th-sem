
read -p "Enter another number: " num2
read -p "Enter a number: " num1

# Prompt the user for the operation to perform
read -p "Enter an operation (+, -, *, /): " operation

# Use the case statement to perform the appropriate operation
case $operation in
  "+")
    result=$((num1 + num2))
    ;;
  "-")
    result=$((num1 - num2))
    ;;
  "*")
    result=$((num1 * num2))
    ;;
  "/")
    result=$((num1 / num2))
    ;;
  *)
    # If the user enters an invalid operation, display an error message
    echo "Invalid operator"
    exit 1
    ;;
esac

# Print the result
echo "Result: $result"


