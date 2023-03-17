function Retrair(){
if (document.getElementById('Retrair').value == "retraindo!"){
 
}

}

function Expor(){
  if (document.getElementById('Expor').value == "expondo!"){

  }
  
  }

  function Automatico(){

    if (document.getElementById('Automatico'). value == "automatico"){

      
      document.getElementById('Automatico').value = "manual"
      document.getElementById('Automatico').textContent = "MODO MANUAL"

      

    }else{
  
     
      document.getElementById('Automatico').value = "automatico"
      document.getElementById('Automatico').textContent = "MODO AUTOMATICO"

    }

}   