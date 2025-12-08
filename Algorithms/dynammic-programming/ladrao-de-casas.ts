/*
Este é um problema clássico de programação dinâmica. A ideia é usar um array para armazenar a quantidade máxima de dinheiro que pode ser roubada até cada casa, sem violar a regra das casas adjacentes.
*/

function rob(nums: number[]): number {
    if (nums.length === 0) return 0;
    if (nums.length === 1) return nums[0];
    
    // Inicializando o array dp (programação dinâmica)
    let dp: number[] = new Array(nums.length).fill(0);
    dp[0] = nums[0];
    dp[1] = Math.max(nums[0], nums[1]);
    
    for (let i = 2; i < nums.length; i++) {
        // Para cada casa, decidimos se vamos roubá-la ou não
        dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    
    return dp[nums.length - 1];
}

// Teste exemplo
const nums = [2, 7, 9, 3, 1];
console.log(rob(nums));  // Saída esperada: 12


// ### Explicação

// 1. **Condições Iniciais:** Se não há casas (`nums.length === 0`), o dinheiro roubado é 0. Se há apenas uma casa (`nums.length === 1`), roubamos o dinheiro dessa casa.
   
// 2. **Inicialização do Array dp:** Criamos um array `dp` onde `dp[i]` representa a quantidade máxima de dinheiro que pode ser roubada até a casa `i`:
//    - `dp[0] = nums[0]`: Se roubamos a primeira casa, a quantidade máxima é o dinheiro nela.
//    - `dp[1] = Math.max(nums[0], nums[1])`: Para a segunda casa, a quantidade máxima é o máximo entre roubar a primeira ou a segunda casa.

// 3. **Preenchimento do Array dp:** Para cada casa a partir da terceira (`i >= 2`):
//    - `dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i])`: Decidimos entre não roubar a casa atual (`dp[i - 1]`) ou roubar a casa atual somando o valor dela ao máximo até a casa `i-2` (`dp[i - 2] + nums[i]`).

// 4. **Resultado Final:** `dp[nums.length - 1]` contém a quantidade máxima de dinheiro que pode ser roubada sem alertar a polícia.

// ### Teste

// No exemplo dado, com as casas tendo os valores `[2, 7, 9, 3, 1]`:
// - A quantidade máxima de dinheiro que pode ser roubada é 12 (roubando as casas com valores 2, 9, e 1).

// Espero que isso ajude a resolver o problema! Se tiver mais dúvidas, estou aqui para ajudar.