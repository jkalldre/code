function canCalc()
{
  var mortgage = document.getElementById('display').innerHTML;
  if (mortgage != '')
    calc();
}

function calc(reset)
{
  // M = loan_amount [ apr(1 + apr)^loan_term ] / [ (1 + apr)^loan_term – 1]
  // mortgage formula
  var monthly_payment = reset;
  var apr = Number(document.getElementById("apr").value);
  apr = (apr / 100) / 12 // monthly rate
  var loan_term = Number(document.getElementById("loanT").value);
  loan_term = loan_term * 12 // term in months
  var loan_amount = Number(document.getElementById("loanA").value);

  if (!validateForm())
  {
    monthly_payment = loan_amount * (apr * ((Math.pow(1 + apr, loan_term)) / (Math.pow(1 + apr, loan_term) - 1)));
    monthly_payment = monthly_payment.toFixed(2);
    if (!isNaN(monthly_payment))
    document.getElementById("display").innerHTML = monthly_payment.toString();

  }


}

function validateForm()
{
  var x = document.getElementById('apr').value;
  var y = document.getElementById('loanT').value;
  var z = document.getElementById('loanA').value;
  var txt1 = document.getElementById('er');
  if (x == "" || y == "" || z == "")
  {
    document.getElementById('err').style.visibility = 'visible';
    txt1.innerHTML = "Please enter required information in ALL fields."
    return false;
  }

}

function reset(id)
{
  document.getElementById(id).innerHTML = '';
}

function hide()
{
  document.getElementById('err').style.visibility = 'hidden';
}
