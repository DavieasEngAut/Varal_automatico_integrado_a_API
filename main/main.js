function Retrair(){
if (document.getElementById('Retrair').value == "retraindo!"){
 
}

}

function Expor(){
  if (document.getElementById('Expor').value == "expondo!"){

  }
  
  }

  function Automatico(){
    
    if (document.getElementById('Automatico').value == "automatico"){

    
      console.log(document.getElementById('Automatico').value)
      window.alert("Modo Automatico Ativado")
      document.getElementById('Automatico').value = "manual"
      document.getElementById('Automatico').textContent = "MODO MANUAL"

      

    }else{
  
      window.alert("Modo Manual Ativado")
      
      console.log(document.getElementById('Automatico').value)
      document.getElementById('Automatico').value = "automatico"
      document.getElementById('Automatico').textContent = "MODO AUTOMATICO"
      
    }

}   