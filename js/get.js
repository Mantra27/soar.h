import fetch from 'node-fetch';
const args = process.argv;
try{
   
    let commandsList = [];  

    args.forEach((e, key)=>{
        if(e == "{}headerisoverhere{}"){
            for(let index = key+1; index < args.length; index++){
                commandsList[commandsList.length] = args[index];
            }
        }
    }); 
    
    const [url, type] = [commandsList[0], commandsList[1]];
            fetch(url, {
                method: 'GET',
            })
            .then(res => { if(type == "text"){return res.text()} else if(type == "json"){return res.json()} })
            .then(data => console.log(data)); 
}
catch(err){
    console.log(err)
}

