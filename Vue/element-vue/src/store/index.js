import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex);

const state = window.sessionStorage.getItem('state') != null? JSON.parse(window.sessionStorage.getItem('state')) :  {
    user:{
        name: '11'
    }
};

const getters={
    getUser(state){
        console.log('getUser::state----', state);
        return state.user;
    }
};

//同步执行更新state.user
const mutations={
    updateUser(state, user){
        state.user=user;
    }
};

//异步执行mutations的方法
const actions={
    asyncUpdateUser(context, user){
        console.log("asyncUpdateUser");
        context.commit("updateUser", user);
        if(user.name) {
            sessionStorage.setItem('state', JSON.stringify(user));
        }
    }
};

export default new Vuex.Store({
    state,
    getters,
    mutations,
    actions,
})
